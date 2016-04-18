#ifndef AS5047.h
#define AS5047.h

class AS5047
{
        public:
                AS5047(uint16_t SelectPin);
                uint32_t sensor_read(void);
                uint32_t error_read(void);
                uint32_t align_and_agc_read(void);
                uint32_t read_register(uint32_t register);
        private:
                const uint16_t _ss;
};
#endif
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               

