/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/mnt/c/Development/J2735/J2735_201603DA.ASN"
 * 	`asn1c -fcompound-names -D /mnt/c/Development/J2735/Gen`
 */

#ifndef	_ConnectionManeuverAssist_H_
#define	_ConnectionManeuverAssist_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LaneConnectionID.h"
#include "ZoneLength.h"
#include "WaitOnStopline.h"
#include "PedestrianBicycleDetect.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RegionalExtension;

/* ConnectionManeuverAssist */
typedef struct ConnectionManeuverAssist {
	LaneConnectionID_t	 connectionID;
	ZoneLength_t	*queueLength	/* OPTIONAL */;
	ZoneLength_t	*availableStorageLength	/* OPTIONAL */;
	WaitOnStopline_t	*waitOnStop	/* OPTIONAL */;
	PedestrianBicycleDetect_t	*pedBicycleDetect	/* OPTIONAL */;
	struct ConnectionManeuverAssist__regional {
		A_SEQUENCE_OF(struct RegionalExtension) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *regional;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ConnectionManeuverAssist_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ConnectionManeuverAssist;
extern asn_SEQUENCE_specifics_t asn_SPC_ConnectionManeuverAssist_specs_1;
extern asn_TYPE_member_t asn_MBR_ConnectionManeuverAssist_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RegionalExtension.h"

#endif	/* _ConnectionManeuverAssist_H_ */
#include <asn_internal.h>
