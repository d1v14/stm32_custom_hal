/*
 * RCC.h
 *
 *  Created on: 15 окт. 2026 г.
 *      Author: dmitr
 */
#ifndef INC_RCC_HPP_
#define INC_RCC_HPP_

#include <cstdint>
#include <type_traits>

class RCCController{
public:
	enum class GpioPort: uint8_t{
		A = 0,
		B = 1,
		C = 2,
		D = 3,
	};

private:
	using gpio_underlying_type = std::underlying_type_t<GpioPort>;
	using rcc_register_address_t = std::uintptr_t;
	using rcc_value_t = std::uint32_t;
	using rcc_register_ptr_t = volatile rcc_register_address_t*;

public:
	RCCController() = delete;
	~RCCController() = delete;


public:
	static void enable_gpio(RCCController::GpioPort gpio){
		rcc_register_ptr_t rcc_register_address = reinterpret_cast<rcc_register_ptr_t>(rcc_register_base_address + rcc_ahb1enr_offset);
		rcc_value_t rcc_register_mask = 1U << static_cast<gpio_underlying_type>(gpio);
		*rcc_register_address |= rcc_register_mask;

		rcc_value_t readback = *rcc_register_address;
		(void) readback;
	}

	static void disable_gpio(RCCController::GpioPort gpio){
		rcc_register_ptr_t rcc_register_address = reinterpret_cast<rcc_register_ptr_t>(rcc_register_base_address + rcc_ahb1enr_offset);
		rcc_value_t rcc_register_mask = ~(1U << static_cast<gpio_underlying_type>(gpio));
		*rcc_register_address &= rcc_register_mask;
	}

private:
	static constexpr inline rcc_register_address_t rcc_register_base_address = 0x4002'3800;
	static constexpr inline rcc_register_address_t rcc_ahb1enr_offset = 0x30;
};


#endif /* INC_RCC_HPP_ */
