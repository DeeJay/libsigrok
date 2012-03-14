/*
 * This file is part of the sigrok project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libusb.h>

#include "command.h"
#include "sigrok.h"
#include "sigrok-internal.h"

int command_start_acquisition(libusb_device_handle *devhdl,
	uint64_t samplerate)
{
	struct cmd_start_acquisition cmd;
	int delay = 0;

	/* Compute the sample rate */
	if((SR_MHZ(48) % samplerate) == 0)
	{
		cmd.flags = CMD_START_FLAGS_CLK_48MHZ;
		delay = SR_MHZ(48) / samplerate - 1;
	} else if((SR_MHZ(30) % samplerate) == 0) {
		cmd.flags = CMD_START_FLAGS_CLK_30MHZ;
		delay = SR_MHZ(30) / samplerate - 1;
	}

	/* Note that sample_delay=0 is treated as sample_delay=256 */
	if (delay <= 0 || delay > 256) {
		sr_err("fx2lafw: Unable to sample at %dHz",
			samplerate);
		return SR_ERR;
	}

	cmd.sample_delay = delay;

	/* Send the control message */
	const int res = libusb_control_transfer(devhdl,
				LIBUSB_REQUEST_TYPE_VENDOR |
				LIBUSB_ENDPOINT_OUT, CMD_START, 0x0000,
				0x0000, (unsigned char*)&cmd,
				sizeof(cmd), 100);
	if (res < 0) {
		sr_err("fx2lafw: Unable to send start command: %d",
			res);
		return SR_ERR;
	}

	return SR_OK;
}