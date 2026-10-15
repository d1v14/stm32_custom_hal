/*
 * GPIO.hpp
 *
 *  Created on: 16 окт. 2026 г.
 *      Author: dmitr
 */

#ifndef INC_GPIO_HPP_
#define INC_GPIO_HPP_

#include <cstdint>

enum class GPIOPort{
	A = 0x0000,
	B = 0x4000,
	C = 0x8000,
	D = 0xC000,
	E = 0x1000,
	H = 0x1C00,
};


class GPIO{
public:
	GPIO() = delete;
	~GPIO() = delete;

public:
	std::uint32_t get_gpio_port_address(GPIOPort port){
		return GPIO_base_address + port;
	}


private:
	static constexpr inline uint32_t GPIO_base_address = 0x4002'0000;
};


#endif /* INC_GPIO_HPP_ */
