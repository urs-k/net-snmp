/* -*- C -*- */
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>

/* pulled from Dave's, yet-to-be-used, net-snmp library rewrite.
   autocompatibility for the future? */

#define NETSNMP_NAMEBUF_LEN 128
typedef struct netsnmp_oid_s {
    unsigned int        *name;
    unsigned int         len;
    unsigned int         namebuf[ NETSNMP_NAMEBUF_LEN ];
} netsnmp_oid;

static int
not_here(char *s)
{
    croak("%s not implemented on this architecture", s);
    return -1;
}

static double
constant(char *name, int len, int arg)
{
    errno = EINVAL;
    return 0;
}




MODULE = NetSNMP::OID		PACKAGE = NetSNMP::OID		PREFIX=nso_

netsnmp_oid *
nso_newptr(char *initstring)
    CODE:
        RETVAL = SNMP_MALLOC_TYPEDEF(netsnmp_oid);
        RETVAL->name = RETVAL->namebuf;
        RETVAL->len = sizeof(RETVAL->namebuf)/sizeof(RETVAL->namebuf[0]);
        if (!snmp_parse_oid(initstring, (oid *) RETVAL->name, &RETVAL->len)) {
            /* XXX: errr */
        }
    OUTPUT:
        RETVAL

double
constant(sv,arg)
    PREINIT:
	STRLEN		len;
    INPUT:
	SV *		sv
	char *		s = SvPV(sv, len);
	int		arg
    CODE:
	RETVAL = constant(s,len,arg);
    OUTPUT:
	RETVAL

int
_snmp_oid_compare(oid1, oid2)
    netsnmp_oid *oid1;
    netsnmp_oid *oid2;
    CODE:
        RETVAL = snmp_oid_compare((oid *) oid1->name, oid1->len,
                                  (oid *) oid2->name, oid2->len);
    OUTPUT:
        RETVAL

MODULE = NetSNMP::OID  PACKAGE = netsnmp_oidPtr  PREFIX = nsop_

void
nsop_DESTROY(oid1)
	netsnmp_oid *oid1
    CODE:
	free(oid1);
        
char *
nsop_to_string(oid1)
    	netsnmp_oid *oid1
    PREINIT:
        static char mystr[SNMP_MAXBUF];
    CODE:
        snprint_objid(mystr, sizeof(mystr),
                      (oid *) oid1->name, oid1->len);
        RETVAL = mystr;
    OUTPUT:
        RETVAL

void
nsop_to_array(oid1)
    netsnmp_oid *oid1;
    PREINIT:
        int i;

    PPCODE:
        EXTEND(SP, oid1->len);
        for(i=0; i < oid1->len; i++) {
            PUSHs(sv_2mortal(newSVnv(oid1->name[i])));
        }

        
