/*
 * app_typedef.h
 *
 *  Created on: Jul 26, 2021
 *      Author: bernardo
 */

#ifndef APP_TYPEDEF_H_
#define APP_TYPEDEF_H_

#include "app_errors.h"

#include <stdint.h>

#define	DEBUG

typedef 	uint16_t 	error_type	;

#define		APP_REPORT(type, id_error)		((type << 8) | id_error)

/*
 * @brief	Enum de canales de medida
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

#define		HTS221		0
#define		GPIO		1
#define		PAC1932		2
#define		PCA9532		3


#endif /* APP_TYPEDEF_H_ */
