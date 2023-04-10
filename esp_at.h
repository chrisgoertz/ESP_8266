/*
 * esp_at.h
 *
 *  Created on: Apr 10, 2023
 *      Author: chris.goertz@gmx.de
 *
 * @brief This Library is intended to use for interfacing
 * STM32 microcontroller with Espressif ESP-8266 WiFi-Modules.
 *
 * license gpl-3.0
 * see https://www.gnu.org/licenses/gpl-3.0.html
 *
 */

#ifndef INC_ESP_AT_H_
#define INC_ESP_AT_H_


// AT COMMAND SET
#define ESP_AT_CHECK 					"AT"
#define ESP_AT_RESTART 					"AT+RST"
#define ESP_AT_VERSION 					"AT+GMR"
#define ESP_AT_MODE 					"AT+CWMODE"
#define ESP_AT_LIST_ACCESS_POINTS 		"AT+CWLAP"
#define ESP_AT_CONNECT 					"AT+CWJAP"
#define ESP_AT_IP_ADDRESS				"AT+CIPSTA"
#define ESP_AT_CONFIGURE_AP				"AT+CWSAP"
#define ESP_AT_LIST_STATIONS			"AT+CWLIF"
#define ESP_AT_CONNECTION_STATUS		"AT+CIPSTATUS"
#define ESP_AT_ESTABLISH_CONNECTION		"AT+CIPSTART"
#define ESP_AT_OBTAIN_IP				"AT+CIFSR"
#define ESP_AT_MULTIPLE_TCP_CONNECTIONS	"AT+CIPMUX"
#define ESP_AT_TCP_SERVER				"AT+CIPSERVER"
#define ESP_AT_OTA_UPDATE				"AT+CIUPDATE"



//
/* AT_MODE enum*/
typedef enum{
	illegal = 0,
	station = 1,
	access_point = 2,
	station_and_access_point = 3
}ESP_ModeTypeDef;

/*Connection State response from WiFi-Module*/
typedef enum{
	illegal = 0,
	connection_timeout = 1,
	wrong_password = 2,
	not_found = 3,
	connection_failed = 4
}ESP_ConnectionStateTypeDef;

typedef enum{
	open = 0,
	wpa_psk = 2,
	wpa2_psk = 3,
	wpa_wpa2_psk = 4

}ESP_EncryptionMethodTypeDef;

typedef enum{
	not_hidden = 0,
	hidden = 1
}ESP_SSID_HiddenStatusTypeDef;

typedef enum{
	optained = 2,
	created_transmission = 3,
	disconnected = 4,
	does_not_connect = 5
}ESP_TCP_UDP_ConnectionStatusTypeDef;


// test uart connection
void esp_check_usart();
// restart module
void esp_restart();
// get version information from mudule
void esp_get_version();
// set wifi mode
void esp_set_mode(esp_at_modes_t mode);
// receive list of available access points
void esp_list_access_points();
// connect to specific ssid
void esp_connect_to_ssid(char* ssid, char* password, char* mac);
// disconnect from ssid
void esp_disconnect_from_ssid();
// receive the ip of the wifi module
void esp_get_ip();
// set the ip of the wifi module
void esp_set_ip(char* ip);
// configure the wifi modules access point
void esp_configure_access_point();
// list clients connected to the wifi module
void esp_list_connected_stations();
// get the connection status from the module
void esp_get_connection_status();
// establish tcp connection to specific ip
void esp_establish_tcp_connection();
//
void esp_obtain_ip();
// set the connection mode to single connection
void esp_set_single_connection();
// set the connection mode to multiple connections
void esp_set_multiple_connections();



#endif /* INC_ESP_AT_H_ */
