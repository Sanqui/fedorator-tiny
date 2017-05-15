#include <Arduino.h>
#include "USBHost_t36.h"  // Read this header first for key info

#include "massstorage.h"

void MassStorageController::init()
{
	contribute_Pipes(mypipes, sizeof(mypipes)/sizeof(Pipe_t));
	contribute_Transfers(mytransfers, sizeof(mytransfers)/sizeof(Transfer_t));
	driver_ready_for_device(this);
	connected = false;
}

bool MassStorageController::claim(Device_t *dev, int type, const uint8_t *descriptors, uint32_t len)
{
	println("MassStorageController claim this=", (uint32_t)this, HEX);

	
	print_hexbytes(descriptors, 32);
	// only claim at interface level
	if (type != 1) return false;
	if (len < 9+9+7) return false;

	uint32_t numendpoint = descriptors[4];
	if (numendpoint < 1) return false;
	if (descriptors[5] != 8) return false; // bInterfaceClass, 8 = Mass Storage
	
	connected = true;
	
	return true;
}

void MassStorageController::control(const Transfer_t *transfer)
{
}

void MassStorageController::callback(const Transfer_t *transfer)
{
	if (transfer->driver) {
		((MassStorageController *)(transfer->driver))->new_data(transfer);
	}
}

void MassStorageController::disconnect()
{
    connected = false;
}


void MassStorageController::new_data(const Transfer_t *transfer)
{
	println("MassStorageController Callback (member)");
}












