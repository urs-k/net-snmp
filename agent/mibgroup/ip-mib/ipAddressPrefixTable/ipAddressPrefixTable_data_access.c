/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id$
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "ipAddressPrefixTable.h"


#include "ipAddressPrefixTable_data_access.h"

#include "ip-mib/ipAddressTable/ipAddressTable.h"

netsnmp_feature_require(ipAddressTable_container_get);
netsnmp_feature_require(ipaddress_common_copy_utilities);
netsnmp_feature_require(ipaddress_prefix_copy);

/** @ingroup interface 
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipAddressPrefixTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * IP-MIB::ipAddressPrefixTable is subid 32 of ip.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.4.32, length: 8
 */

/**
 * initialization for ipAddressPrefixTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param ipAddressPrefixTable_reg
 *        Pointer to ipAddressPrefixTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
ipAddressPrefixTable_init_data(ipAddressPrefixTable_registration *
                               ipAddressPrefixTable_reg)
{
    DEBUGMSGTL(("verbose:ipAddressPrefixTable:ipAddressPrefixTable_init_data", "called\n"));

    /*
     * TODO:303:o: Initialize ipAddressPrefixTable data.
     */

    return MFD_SUCCESS;
}                               /* ipAddressPrefixTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
ipAddressPrefixTable_container_init(netsnmp_container **container_ptr_ptr,
                                    netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:ipAddressPrefixTable:ipAddressPrefixTable_container_init", "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to ipAddressPrefixTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,
                 "bad cache param to ipAddressPrefixTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up ipAddressPrefixTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = IPADDRESSPREFIXTABLE_CACHE_TIMEOUT;        /* seconds */
}                               /* ipAddressPrefixTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before ipAddressPrefixTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
ipAddressPrefixTable_container_shutdown(netsnmp_container *container_ptr)
{
    DEBUGMSGTL(("verbose:ipAddressPrefixTable:ipAddressPrefixTable_container_shutdown", "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to ipAddressPrefixTable_container_shutdown\n");
        return;
    }

}                               /* ipAddressPrefixTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement ipAddressPrefixTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  ipAddressPrefixTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
ipAddressPrefixTable_container_load(netsnmp_container *container)
{
    ipAddressPrefixTable_rowreq_ctx *rowreq_ctx = NULL, *tmp_rowreq_ctx;
    ipAddressTable_rowreq_ctx *addr_rowreq_ctx;
    netsnmp_container *addr_container;
    netsnmp_iterator *addr_it;
    int             count = 0;
    u_char          tmp_pfx[NETSNMP_ACCESS_IPADDRESS_BUF_SIZE];

    DEBUGMSGTL(("verbose:ipAddressPrefixTable:ipAddressPrefixTable_container_load", "called\n"));

    addr_container = ipAddressTable_container_get();
    if (NULL == addr_container) {
        DEBUGMSGTL(("ipAddressPrefixTable:container_load",
                    "couldn't get ipAddress container\n"));
        return MFD_RESOURCE_UNAVAILABLE;
    }

    addr_it = CONTAINER_ITERATOR(addr_container);
    if (NULL == addr_container) {
        DEBUGMSGTL(("ipAddressPrefixTable:container_load",
                    "couldn't get ipAddress iterator\n"));
        return MFD_RESOURCE_UNAVAILABLE;
    }

    /*
     * TODO:351:M: |-> Load/update data in the ipAddressPrefixTable container.
     * loop over your ipAddressPrefixTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    for (addr_rowreq_ctx = ITERATOR_FIRST(addr_it);
         addr_rowreq_ctx; addr_rowreq_ctx = ITERATOR_NEXT(addr_it)) {



        /*
         * TODO:352:M: |   |-> set indexes in new ipAddressPrefixTable rowreq context.
         * data context will be set from the param (unless NULL,
         *      in which case a new data context will be allocated)
         */
        if (NULL == rowreq_ctx) {
            rowreq_ctx = ipAddressPrefixTable_allocate_rowreq_ctx(NULL);
            if (NULL == rowreq_ctx) {
                snmp_log(LOG_ERR, "memory allocation failed\n");
                ITERATOR_RELEASE(addr_it);
                return MFD_RESOURCE_UNAVAILABLE;
            }
        }
        netsnmp_ipaddress_prefix_copy(tmp_pfx,
                                      addr_rowreq_ctx->tbl_idx.
                                      ipAddressAddr,
                                      addr_rowreq_ctx->data->
                                      ia_address_len,
                                      addr_rowreq_ctx->data->
                                      ia_prefix_len);
        netsnmp_ipaddress_flags_copy(&rowreq_ctx->data.
                                     ipAddressPrefixAdvPreferredLifetime,
                                     &rowreq_ctx->data.
                                     ipAddressPrefixAdvValidLifetime,
                                     &rowreq_ctx->data.
                                     ipAddressPrefixOnLinkFlag,
                                     &rowreq_ctx->data.
                                     ipAddressPrefixAutonomousFlag,  
                                     &addr_rowreq_ctx->data->
                                     ia_prefered_lifetime,
                                     &addr_rowreq_ctx->data->
                                     ia_valid_lifetime,
                                     &addr_rowreq_ctx->data->
                                     ia_onlink_flag,
                                     &addr_rowreq_ctx->data->
                                     ia_autonomous_flag);

        if (MFD_SUCCESS !=
            ipAddressPrefixTable_indexes_set(rowreq_ctx,
                                             addr_rowreq_ctx->data->
                                             if_index,
                                             addr_rowreq_ctx->tbl_idx.
                                             ipAddressAddrType, tmp_pfx,
                                             addr_rowreq_ctx->data->
                                             ia_address_len,
                                             addr_rowreq_ctx->data->
                                             ia_prefix_len)) {
            snmp_log(LOG_ERR,
                     "error setting index while loading "
                     "ipAddressPrefixTable data.\n");
            ipAddressPrefixTable_release_rowreq_ctx(rowreq_ctx);
            rowreq_ctx = NULL;
            continue;
        }

        /** do we already have this prefix? */
        tmp_rowreq_ctx = CONTAINER_FIND(container, rowreq_ctx);
        if (NULL != tmp_rowreq_ctx)
            continue;

        /*
         * TODO:352:r: |   |-> populate ipAddressPrefixTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
           netsnmp_ipaddress_prefix_origin_copy(&rowreq_ctx->data.
                                             ipAddressPrefixOrigin,
                                             addr_rowreq_ctx->data->
                                             ia_origin,
                                             addr_rowreq_ctx->data->
                                             flags,
                                             addr_rowreq_ctx->tbl_idx.
                                             ipAddressAddrType);

        /** defer the rest til row prep */

        /*
         * insert into table container, clear ptr so we reallocate
         */
        if (CONTAINER_INSERT(container, rowreq_ctx) == 0) {
          rowreq_ctx = NULL;
          ++count;
        }
    }
    ITERATOR_RELEASE(addr_it);

    /** clean up if "do we already have this prefix?" was true and no CONTAINER_INSERT happened afterwards */
    if (rowreq_ctx) {
      ipAddressPrefixTable_release_rowreq_ctx(rowreq_ctx);
    }

    DEBUGMSGT(("verbose:ipAddressPrefixTable:ipAddressPrefixTable_container_load", "inserted %d records\n", count));

    return MFD_SUCCESS;
}                               /* ipAddressPrefixTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
ipAddressPrefixTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:ipAddressPrefixTable:ipAddressPrefixTable_container_free", "called\n"));

    /*
     * TODO:380:M: Free ipAddressPrefixTable container data.
     */
}                               /* ipAddressPrefixTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
ipAddressPrefixTable_row_prep(ipAddressPrefixTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ipAddressPrefixTable:ipAddressPrefixTable_row_prep", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */
    if (INETADDRESSTYPE_IPV6 == rowreq_ctx->tbl_idx.ipAddressPrefixType) {

    }

    return MFD_SUCCESS;
}                               /* ipAddressPrefixTable_row_prep */

/** @} */
