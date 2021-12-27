/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set c4 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void c4_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set c4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void c4_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(0, dir);
}

/**
 * \brief Set c4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void c4_set_level(const bool level)
{
	PORTB_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on c4
 *
 * Toggle the pin level
 */
static inline void c4_toggle_level()
{
	PORTB_toggle_pin_level(0);
}

/**
 * \brief Get level on c4
 *
 * Reads the level on a pin
 */
static inline bool c4_get_level()
{
	return PORTB_get_pin_level(0);
}

/**
 * \brief Set c3 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void c3_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set c3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void c3_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(1, dir);
}

/**
 * \brief Set c3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void c3_set_level(const bool level)
{
	PORTB_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on c3
 *
 * Toggle the pin level
 */
static inline void c3_toggle_level()
{
	PORTB_toggle_pin_level(1);
}

/**
 * \brief Get level on c3
 *
 * Reads the level on a pin
 */
static inline bool c3_get_level()
{
	return PORTB_get_pin_level(1);
}

/**
 * \brief Set c2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void c2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set c2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void c2_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(2, dir);
}

/**
 * \brief Set c2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void c2_set_level(const bool level)
{
	PORTD_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on c2
 *
 * Toggle the pin level
 */
static inline void c2_toggle_level()
{
	PORTD_toggle_pin_level(2);
}

/**
 * \brief Get level on c2
 *
 * Reads the level on a pin
 */
static inline bool c2_get_level()
{
	return PORTD_get_pin_level(2);
}

/**
 * \brief Set c1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void c1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set c1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void c1_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(3, dir);
}

/**
 * \brief Set c1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void c1_set_level(const bool level)
{
	PORTD_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on c1
 *
 * Toggle the pin level
 */
static inline void c1_toggle_level()
{
	PORTD_toggle_pin_level(3);
}

/**
 * \brief Get level on c1
 *
 * Reads the level on a pin
 */
static inline bool c1_get_level()
{
	return PORTD_get_pin_level(3);
}

/**
 * \brief Set r4 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void r4_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set r4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void r4_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(4, dir);
}

/**
 * \brief Set r4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void r4_set_level(const bool level)
{
	PORTD_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on r4
 *
 * Toggle the pin level
 */
static inline void r4_toggle_level()
{
	PORTD_toggle_pin_level(4);
}

/**
 * \brief Get level on r4
 *
 * Reads the level on a pin
 */
static inline bool r4_get_level()
{
	return PORTD_get_pin_level(4);
}

/**
 * \brief Set r3 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void r3_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set r3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void r3_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(5, dir);
}

/**
 * \brief Set r3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void r3_set_level(const bool level)
{
	PORTD_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on r3
 *
 * Toggle the pin level
 */
static inline void r3_toggle_level()
{
	PORTD_toggle_pin_level(5);
}

/**
 * \brief Get level on r3
 *
 * Reads the level on a pin
 */
static inline bool r3_get_level()
{
	return PORTD_get_pin_level(5);
}

/**
 * \brief Set r2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void r2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(6, pull_mode);
}

/**
 * \brief Set r2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void r2_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(6, dir);
}

/**
 * \brief Set r2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void r2_set_level(const bool level)
{
	PORTD_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on r2
 *
 * Toggle the pin level
 */
static inline void r2_toggle_level()
{
	PORTD_toggle_pin_level(6);
}

/**
 * \brief Get level on r2
 *
 * Reads the level on a pin
 */
static inline bool r2_get_level()
{
	return PORTD_get_pin_level(6);
}

/**
 * \brief Set r1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void r1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(7, pull_mode);
}

/**
 * \brief Set r1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void r1_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(7, dir);
}

/**
 * \brief Set r1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void r1_set_level(const bool level)
{
	PORTD_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on r1
 *
 * Toggle the pin level
 */
static inline void r1_toggle_level()
{
	PORTD_toggle_pin_level(7);
}

/**
 * \brief Get level on r1
 *
 * Reads the level on a pin
 */
static inline bool r1_get_level()
{
	return PORTD_get_pin_level(7);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
