/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/mnt/c/Development/J2735/J2735_201603DA.ASN"
 * 	`asn1c -fcompound-names -D /mnt/c/Development/J2735/Gen`
 */

#ifndef	_MultiVehicleResponse_H_
#define	_MultiVehicleResponse_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MultiVehicleResponse {
	MultiVehicleResponse_unavailable	= 0,
	MultiVehicleResponse_singleVehicle	= 1,
	MultiVehicleResponse_multiVehicle	= 2,
	MultiVehicleResponse_reserved	= 3
} e_MultiVehicleResponse;

/* MultiVehicleResponse */
typedef long	 MultiVehicleResponse_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_MultiVehicleResponse_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_MultiVehicleResponse;
extern const asn_INTEGER_specifics_t asn_SPC_MultiVehicleResponse_specs_1;
asn_struct_free_f MultiVehicleResponse_free;
asn_struct_print_f MultiVehicleResponse_print;
asn_constr_check_f MultiVehicleResponse_constraint;
ber_type_decoder_f MultiVehicleResponse_decode_ber;
der_type_encoder_f MultiVehicleResponse_encode_der;
xer_type_decoder_f MultiVehicleResponse_decode_xer;
xer_type_encoder_f MultiVehicleResponse_encode_xer;
oer_type_decoder_f MultiVehicleResponse_decode_oer;
oer_type_encoder_f MultiVehicleResponse_encode_oer;
per_type_decoder_f MultiVehicleResponse_decode_uper;
per_type_encoder_f MultiVehicleResponse_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _MultiVehicleResponse_H_ */
#include <asn_internal.h>
