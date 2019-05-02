/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/mnt/c/Development/J2735/J2735_201603DA.ASN"
 * 	`asn1c -fcompound-names -D /mnt/c/Development/J2735/Gen`
 */

#ifndef	_LaneAttributes_Parking_H_
#define	_LaneAttributes_Parking_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LaneAttributes_Parking {
	LaneAttributes_Parking_parkingRevocableLane	= 0,
	LaneAttributes_Parking_parallelParkingInUse	= 1,
	LaneAttributes_Parking_headInParkingInUse	= 2,
	LaneAttributes_Parking_doNotParkZone	= 3,
	LaneAttributes_Parking_parkingForBusUse	= 4,
	LaneAttributes_Parking_parkingForTaxiUse	= 5,
	LaneAttributes_Parking_noPublicParkingUse	= 6
} e_LaneAttributes_Parking;

/* LaneAttributes-Parking */
typedef BIT_STRING_t	 LaneAttributes_Parking_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_LaneAttributes_Parking_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_LaneAttributes_Parking;
asn_struct_free_f LaneAttributes_Parking_free;
asn_struct_print_f LaneAttributes_Parking_print;
asn_constr_check_f LaneAttributes_Parking_constraint;
ber_type_decoder_f LaneAttributes_Parking_decode_ber;
der_type_encoder_f LaneAttributes_Parking_encode_der;
xer_type_decoder_f LaneAttributes_Parking_decode_xer;
xer_type_encoder_f LaneAttributes_Parking_encode_xer;
oer_type_decoder_f LaneAttributes_Parking_decode_oer;
oer_type_encoder_f LaneAttributes_Parking_encode_oer;
per_type_decoder_f LaneAttributes_Parking_decode_uper;
per_type_encoder_f LaneAttributes_Parking_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _LaneAttributes_Parking_H_ */
#include <asn_internal.h>
