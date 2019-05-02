/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/mnt/c/Development/J2735/J2735_201603DA.ASN"
 * 	`asn1c -fcompound-names -D /mnt/c/Development/J2735/Gen`
 */

#ifndef	_DescriptiveName_H_
#define	_DescriptiveName_H_


#include <asn_application.h>

/* Including external dependencies */
#include <IA5String.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DescriptiveName */
typedef IA5String_t	 DescriptiveName_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DescriptiveName_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DescriptiveName;
asn_struct_free_f DescriptiveName_free;
asn_struct_print_f DescriptiveName_print;
asn_constr_check_f DescriptiveName_constraint;
ber_type_decoder_f DescriptiveName_decode_ber;
der_type_encoder_f DescriptiveName_encode_der;
xer_type_decoder_f DescriptiveName_decode_xer;
xer_type_encoder_f DescriptiveName_encode_xer;
oer_type_decoder_f DescriptiveName_decode_oer;
oer_type_encoder_f DescriptiveName_encode_oer;
per_type_decoder_f DescriptiveName_decode_uper;
per_type_encoder_f DescriptiveName_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _DescriptiveName_H_ */
#include <asn_internal.h>
