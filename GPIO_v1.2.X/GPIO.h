#ifndef GPIO_H_
#define GPIO_H_

class GPIO {
public:
	enum PortDirection_t {
		INPUT = 0,
		OUTPUT = 1
	};
	GPIO(uint8_t id, PortDirection_t dir);
	~GPIO();

	bool get();
	void set(bool val = 1);
	void clear();
	void toggle();
private:
	uint8_t _bit;
    uint8_t * _DDR;
    uint8_t * _PORT;
    uint8_t * _PIN;
};

