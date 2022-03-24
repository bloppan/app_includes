/*
 * app_errors.h
 *
 *  Created on: 22 nov. 2021
 *      Author: bernardo
 */

#ifndef APP_ERRORS_H_
#define APP_ERRORS_H_

#include "app_typedef.h"

#include <stdint.h>

typedef 	uint16_t 	error_type	;

#define		APP_REPORT(type, id_error)		((type << 8) | id_error)

/*
 * Peripherals definition (type error)
 */
#define		NO_ERROR		0
#define		I2C				1
#define		HTS221			2
#define		GPIO			3
#define		PAC1932			4
#define		PCA9532			5
#define		CAN				6
#define		WSEN_TIDS		7
#define		APP_DAEMON		8
/*
 * GPIO Errors	(id_error)
 */
#define		OPENING_EXPORT_FILE				1
#define		WRITING_EXPORT_FILE				2
#define		OPENING_DIRECTION_FILE			3
#define		WRITING_DIRECTION_FILE			4
#define		INVALID_OUTPUT_VALUE			5
#define		OPENING_UNEXPORT_FILE			6
#define		WRITING_UNEXPORT_FILE			7
#define		OPENING_VALUE_FILE				8
#define		INVALID_DIRECTION_VALUE			9
#define		WRITING_VALUE_FILE				10
#define		READING_VALUE_FILE				11
#define		READING_DIRECTION_FILE			12
/**
 * @brief: Errores bus CAN (id_error)
 */
#define		OPENING_SOCKET					13
#define		WRITING_IOCTL_FILE				14
#define		BIND_CALL						15
#define		SEND_FRAME						16
#define		RECEIVE_FRAME					17
/*
 * HTS221 Errors (id_error)
 */
#define		LOADING_I2C_LIBRARY				18
#define		READING_CALIBRATION_VALUES		19
#define		READING_HUMIDITY				20
#define		READING_TEMPERATURE				21
/*
 * I2C Errors	(id_error)
 */
#define		OPENING_I2C_PORT				22
/*
 * PAC1932 Errors	(id_error)
 */
#define		LOADING_GPIO_LIBRARY			23
#define		READING_PAC1932_VALUES			24
/*
 * PCA9532 Errors
 */
#define		INCORRECT_COLOR					25
#define		SETTING_LED_COLOR				26
/*
 * WSEN-TIDS Errors (id error)
 */
#define		SEND_RESET_COMMAND				27
#define		SEND_CTRL_COMMAND				28
/*
 * APP DAEMON Errors (id error)
 */
#define		CONNECTION_LOST					29
#define		SELECT_SOCKET					30
#define		READING_SOCKET					31
#define		WRITING_SOCKET					32
#define		CLOSING_SOCKET					33
#define		CONNECTING_SOCKET				34


#endif /* APP_ERRORS_H_ */
