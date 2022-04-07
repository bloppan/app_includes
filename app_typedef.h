/*
 * app_typedef.h
 *
 *  Created on: Jul 26, 2021
 *      Author: bernardo
 */

#ifndef APP_TYPEDEF_H_
#define APP_TYPEDEF_H_

#include "app_errors.h"

#include <linux/can.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <stdint.h>

#define	DEBUG

#define 	GPIO_NUMBER(bank, index)    ((((bank)-1)*32)+((index)&31))

/*
 * GPIO Definition
 */
#define		SIM_CTRL				GPIO_NUMBER(5, 7)		// Multiplexor de tarjeta SIM 					(id 135, J2.37 <-- 127)
#define		PORTASIM_PRES			GPIO_NUMBER(1, 0)		// Detector del PortaSIM 						(id 36,  J2.80 <-- 170)
#define		SAI_DETECT				GPIO_NUMBER(1, 24)		// Detector de alimentacion SAI					(id 24,  J1.59)
#define		EN_5V_USB_MOB			GPIO_NUMBER(5, 9)		// Conector USB 5V del terminal movil			(id 137, J2.49 <-- 139)
#define		EN_4V2					GPIO_NUMBER(1, 4)		// Conector 4V2 bateria del terminal movil		(id 4,   J2.52 <-- 142)
#define		PWDN_CURR_SENSOR		GPIO_NUMBER(5, 1)		// Enable PAC1932								(id 129, J2.64 <-- 154)
#define		ALERT_CURR_SENSOR		GPIO_NUMBER(5, 8)		// Alert PAC1932								(id 136, J2.39 <-- 129)
#define		TEMP_DRDY				GPIO_NUMBER(1, 0)		// Temp data ready								(id 0,   J2.60 <-- 150)
#define		LED_RST					GPIO_NUMBER(1, 2)		// Enable PCA9532 								(id 2,   J2.48 <-- 138)
#define		FANOUT_1				GPIO_NUMBER(1, 5)		// Ventilador 1
#define		FANOUT_2				GPIO_NUMBER(1, 9)		// Ventilador 2


#define		NO_BLINK		0		// Sin parpadeo
#define		BLINK_LVL_1		1		// Parpadeo nivel 1
#define		BLINK_LVL_2		2		// Parpadeo nivel 2

/*
 * @brief	Enum de canales de medida de valores electricos
 */
typedef enum {

	SOM,
	Peripherals,
	Terminal_Battery,
	USB_Connector

}Channels_Enum;

/*
 * @brief	Estructura que almacena valores electricos de un canal
 */
typedef struct {

	float	Intensity;	// Valor de intensidad en miliamperios (mA)
	float	Voltage;	// Valor de voltaje en voltios (V)
	float 	Power;		// Valor de potencia consumida en watios (W)

}Electrial_Values_struct;

/*
 * @brief	Estructura que almacena los datos del sensor PAC1932
 */
typedef struct {

	Electrial_Values_struct	SOM;				// Estructura que contiene los valores electricos del SOM
	Electrial_Values_struct Peripherals;		// Estructura que contiene los valores electricos de los perifericos
	Electrial_Values_struct	Terminal_Battery;	// Estructura que contiene los valores electricos del terminal movil
	Electrial_Values_struct USB_Connector;		// Estructura que contiene los valores electricos del conector USB

	uint32_t	Acc_Count;	// Numero de acumulaciones (sumas) realizadas en los registros VPOWERn_ACC

}PAC1932_struct;

/*
 * @brief Estructura que almacena la informacion de un mensaje CAN
 */
struct can_message {

	struct can_frame frame;
	struct sockaddr_can addr;
	struct ifreq ifr;
	int socket;

};

#endif /* APP_TYPEDEF_H_ */
