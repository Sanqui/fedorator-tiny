class MassStorageController : public USBDriver {
    public:
	    MassStorageController(USBHost &host) { init(); }
	    MassStorageController(USBHost *host) { init(); }
	    int      available();
	    int      read();
	    bool connected;
    protected:
	    virtual bool claim(Device_t *device, int type, const uint8_t *descriptors, uint32_t len);
	    virtual void control(const Transfer_t *transfer);
	    virtual void disconnect();
	    static void callback(const Transfer_t *transfer);
	    void new_data(const Transfer_t *transfer);
	    void init();
    private:
	    Pipe_t mypipes[2] __attribute__ ((aligned(32)));
	    Transfer_t mytransfers[4] __attribute__ ((aligned(32)));
};
