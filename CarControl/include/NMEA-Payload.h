/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/mnt/c/Development/J2735/J2735_201603DA.ASN"
 * 	`asn1c -fcompound-names -D /mnt/c/Development/J2735/Gen`
 */

#ifndef	_NMEA_Payload_H_
#define	_NMEA_Payload_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NMEA-Payload */
typedef OCTET_STRING_t	 NMEA_Payload_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NMEA_Payload_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NMEA_Payload;
asn_struct_free_f NMEA_Payload_free;
asn_struct_print_f NMEA_Payload_print;
asn_constr_check_f NMEA_Payload_constraint;
ber_type_decoder_f NMEA_Payload_decode_ber;
der_type_encoder_f NMEA_Payload_encode_der;
xer_type_decoder_f NMEA_Payload_decode_xer;
xer_type_encoder_f NMEA_Payload_encode_xer;
oer_type_decoder_f NMEA_Payload_decode_oer;
oer_type_encoder_f NMEA_Payload_encode_oer;
per_type_decoder_f NMEA_Payload_decode_uper;
per_type_encoder_f NMEA_Payload_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _NMEA_Payload_H_ */
#include <asn_internal.h>
