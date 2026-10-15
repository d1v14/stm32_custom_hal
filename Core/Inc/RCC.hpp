/*
 * RCC.h
 *
 *  Created on: 15 окт. 2026 г.
 *      Author: dmitr
 */
#ifndef INC_RCC_HPP_
#define INC_RCC_HPP_

#include <cstdint>
#include "GPIO.hpp"

class RCC{
public:
	RCC() = delete;
	~RCC() = delete;


public:
	static void enable_gpio(GPIO gpio_port){

	}

private:
	static constexpr inline uint32_t RCC_AHB1ENR = 0x30;
//
};


#endif /* INC_RCC_HPP_ */
