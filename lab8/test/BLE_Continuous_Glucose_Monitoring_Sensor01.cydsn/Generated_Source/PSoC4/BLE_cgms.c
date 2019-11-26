/***************************************************************************//**
* \file CYBLE_cgms.c
* \version 3.30
* 
* \brief
*  This file contains the source code for the Continuous Glucose Monitoring
*  Service of the BLE Component.
* 
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "BLE_eventHandler.h"

static CYBLE_CALLBACK_T CyBle_CgmsApplCallback;

#ifdef CYBLE_CGMS_SERVER

const CYBLE_CGMSS_T cyBle_cgmss =
{
    0x000Eu,    /* Handle of the CGMS service */
    {
        
        /* CGM Measurement characteristic */
        {
            0x0010u, /* Handle of the CGM Measurement characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x0011u, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
        
        /* CGM Feature characteristic */
        {
            0x0013u, /* Handle of the CGM Feature characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* CGM Status characteristic */
        {
            0x0015u, /* Handle of the CGM Status characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* CGM Session Start Time characteristic */
        {
            0x0017u, /* Handle of the CGM Session Start Time characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* CGM Session Run Time characteristic */
        {
            0x0019u, /* Handle of the CGM Session Run Time characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Record Access Control Point characteristic */
        {
            0x001Bu, /* Handle of the Record Access Control Point characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x001Cu, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
        
        /* CGM Specific Ops Control Point characteristic */
        {
            0x001Eu, /* Handle of the CGM Specific Ops Control Point characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x001Fu, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
    },
};
    
    uint8 cyBle_cgmsFlag;
    
static CYBLE_GATT_DB_ATTR_HANDLE_T cyBle_cgmssReqHandle;

#endif /* CYBLE_CGMS_SERVER */

#ifdef CYBLE_CGMS_CLIENT
    
/* Server's CGM Service characteristics GATT DB handles structure */
CYBLE_CGMSC_T cyBle_cgmsc;

/* Internal storage for last request handle to check response */
static CYBLE_GATT_DB_ATTR_HANDLE_T cyBle_cgmscReqHandle;
#endif /* CYBLE_CGMS_CLIENT */


/****************************************************************************** 
* Function Name: CyBle_CgmsInit
***************************************************************************//**
* 
*  Initializes the profile internals.
* 

******************************************************************************/
void CyBle_CgmsInit(void)
{
#ifdef CYBLE_CGMS_SERVER
    cyBle_cgmsFlag = 0u;
    cyBle_cgmssReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
#endif /* CYBLE_CGMS_SERVER */
#ifdef CYBLE_CGMS_CLIENT
    if(cyBle_serverInfo[CYBLE_SRVI_CGMS].range.startHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
        (void)memset(&cyBle_cgmsc, 0, sizeof(cyBle_cgmsc));
    }
    cyBle_cgmscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
#endif /* CYBLE_GATT_ROLE_CLIENT */
}


/******************************************************************************
* Function Name: CyBle_CgmsRegisterAttrCallback
***************************************************************************//**
* 
*  Registers a callback function for service specific attribute operations.
*  Service specific write requests from peer device will not be handled with
*  unregistered callback function.
* 
*  \param callbackFunc:  An application layer event callback function to receive 
*                    events from the BLE Component. The definition of 
*                    CYBLE_CALLBACK_T for CGM Service is,       
*                    typedef void (* CYBLE_CALLBACK_T) (uint32 eventCode, 
*                                                       void *eventParam)
*                    * eventCode indicates the event that triggered this 
*                      callback.
*                    * eventParam contains the parameters corresponding to the 
*                      current event.
* 

* \sideeffect The *eventParams in the callback function should not be used 
*                by the application once the callback function execution is 
*                finished. Otherwise this data may become corrupted.
* 
******************************************************************************/
void CyBle_CgmsRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc)
{
    CyBle_CgmsApplCallback = callbackFunc;
}


#ifdef CYBLE_CGMS_SERVER


/******************************************************************************
* Function Name: CyBle_CgmssSetCharacteristicValue
***************************************************************************//**
* 
*  Sets a characteristic value of the service identified by charIndex.
* 
*  \param charIndex: The index of a service characteristic.
*  \param attrSize: The size of the characteristic value attribute.
*  \param attrValue: The pointer to the characteristic value data that should be
*               stored in the GATT database.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request handled successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - An optional characteristic is absent.

******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmssSetCharacteristicValue(CYBLE_CGMS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(charIndex >= CYBLE_CGMS_CHAR_COUNT) 
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(cyBle_cgmss.charInfo[charIndex].charHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
        apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
    }
    else
    {
        CYBLE_GATT_HANDLE_VALUE_PAIR_T locHandleValuePair;
        
        /* Store characteristic value into GATT database */
        locHandleValuePair.attrHandle = cyBle_cgmss.charInfo[charIndex].charHandle;
        locHandleValuePair.value.len = attrSize;
        locHandleValuePair.value.val = attrValue;
        
        if(CYBLE_GATT_ERR_NONE != CyBle_GattsWriteAttributeValue(&locHandleValuePair,
                                    0u, NULL, CYBLE_GATT_DB_LOCALLY_INITIATED))
        {
            apiResult = CYBLE_ERROR_INVALID_PARAMETER;
        }
        else
        {
            apiResult = CYBLE_ERROR_OK;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmssGetCharacteristicValue
***************************************************************************//**
* 
*  Gets a characteristic value of the service identified by charIndex.
* 
*  \param charIndex: The index of a service characteristic.
*  \param attrSize: The size of the characteristic value attribute.
*  \param attrValue: The pointer to the location where Characteristic value data should 
*               be stored.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request handled successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - An optional characteristic is absent.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmssGetCharacteristicValue(CYBLE_CGMS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check the parameters */
    if(charIndex >= CYBLE_CGMS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(cyBle_cgmss.charInfo[charIndex].charHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
        apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
    }
    else
    {
        CYBLE_GATT_HANDLE_VALUE_PAIR_T locHandleValuePair;
        
        /* Get characteristic value from GATT database */
        locHandleValuePair.attrHandle = cyBle_cgmss.charInfo[charIndex].charHandle;
        locHandleValuePair.value.len = attrSize;
        locHandleValuePair.value.val = attrValue;
        
        if(CYBLE_GATT_ERR_NONE != CyBle_GattsReadAttributeValue(&locHandleValuePair,
                                    0u, CYBLE_GATT_DB_LOCALLY_INITIATED))
        {
            apiResult = CYBLE_ERROR_INVALID_PARAMETER;
        }
        else
        {
            apiResult = CYBLE_ERROR_OK;
        }
    }

    return (apiResult);
}


/****************************************************************************** 
* Function Name: CyBle_CgmssSetCharacteristicDescriptor
***************************************************************************//**
* 
*  Sets a characteristic descriptor of a specified characteristic of the service.
* 
*  \param charIndex:       The index of a service characteristic of type 
*                   CYBLE_CGMS_CHAR_INDEX_T.
*  \param descrIndex:      The index of a service characteristic descriptor of type 
*                   CYBLE_CGMS_DESCR_INDEX_T.
*  \param attrSize:        The size of the characteristic descriptor attribute.
*  \param attrValue:      The pointer to the descriptor value data that should 
*                   be stored to the GATT database. 
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request is handled successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmssSetCharacteristicDescriptor(CYBLE_CGMS_CHAR_INDEX_T charIndex,
    CYBLE_CGMS_DESCR_INDEX_T descrIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult = CYBLE_ERROR_OK;
    CYBLE_GATT_HANDLE_VALUE_PAIR_T locHandleValuePair;

    if((charIndex >= CYBLE_CGMS_CHAR_COUNT) || (descrIndex >= CYBLE_CGMS_DESCR_COUNT))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else
    {
        locHandleValuePair.attrHandle = cyBle_cgmss.charInfo[charIndex].descrHandle[descrIndex];
        locHandleValuePair.value.len = attrSize;
        locHandleValuePair.value.val = attrValue;
        if(CYBLE_GATT_ERR_NONE !=
                CyBle_GattsWriteAttributeValue(&locHandleValuePair, 0u, NULL, CYBLE_GATT_DB_LOCALLY_INITIATED))
        {
            apiResult = CYBLE_ERROR_INVALID_PARAMETER;
        }
    }
    return (apiResult);
}


/****************************************************************************** 
* Function Name: CyBle_CgmssGetCharacteristicDescriptor
***************************************************************************//**
* 
*  Gets a characteristic descriptor of a specified characteristic of the service.
* 
*  \param charIndex:       The index of a service characteristic of type 
*                   CYBLE_CGMS_CHAR_INDEX_T.
*  \param descrIndex:      The index of a service characteristic descriptor of type 
*                   CYBLE_CGMS_DESCR_INDEX_T.
*  \param attrSize:        The size of the characteristic descriptor attribute.
*  \param attrValue:      The pointer to the location where characteristic descriptor
*                   value data should be stored.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request handled successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmssGetCharacteristicDescriptor(CYBLE_CGMS_CHAR_INDEX_T charIndex,
    CYBLE_CGMS_DESCR_INDEX_T descrIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult = CYBLE_ERROR_OK;
    CYBLE_GATT_HANDLE_VALUE_PAIR_T locHandleValuePair;

    if((charIndex >= CYBLE_CGMS_CHAR_COUNT) || (descrIndex >= CYBLE_CGMS_DESCR_COUNT))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else
    {
        locHandleValuePair.attrHandle = cyBle_cgmss.charInfo[charIndex].descrHandle[descrIndex];
        locHandleValuePair.value.len = attrSize;
        locHandleValuePair.value.val = attrValue;
        if(CYBLE_GATT_ERR_NONE !=
                CyBle_GattsReadAttributeValue(&locHandleValuePair, NULL, CYBLE_GATT_DB_LOCALLY_INITIATED))
        {
            apiResult = CYBLE_ERROR_INVALID_PARAMETER;
        }
    }
    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmssSendNotification
***************************************************************************//**
* 
*  Sends a notification of the specified characteristic to the client device, 
*  as defined by the charIndex value.
*
*  On enabling notification successfully for a service characteristic, if the GATT
*  server has an updated value to be notified to the GATT Client, it sends out a
*  'Handle Value Notification' which results in CYBLE_EVT_CGMSC_NOTIFICATION event
*  at the GATT Client's end.
* 
*  \param connHandle: The connection handle which consists of the device ID and ATT 
*               connection ID.
*  \param charIndex: The index of the service characteristic.
*  \param attrSize: The size of the characteristic value attribute.
*  \param attrValue: The pointer to the Characteristic value data that should be sent 
*               to the client device.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*   * CYBLE_ERROR_OK - The request handled successfully
*   * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*   * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this 
*                                      characteristic.
*   * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - An optional characteristic is absent.
*   * CYBLE_ERROR_INVALID_STATE - Connection with the client is not established.
*   * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*   * CYBLE_ERROR_NTF_DISABLED - Notification is not enabled by the client.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmssSendNotification(CYBLE_CONN_HANDLE_T connHandle,
                    CYBLE_CGMS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Send notification if it is enabled and connected */
    if(CYBLE_STATE_CONNECTED != CyBle_GetState())
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if(charIndex >= CYBLE_CGMS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(cyBle_cgmss.charInfo[charIndex].charHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
        apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
    }
    else if(!CYBLE_IS_NOTIFICATION_ENABLED(cyBle_cgmss.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD]))
    {
        apiResult = CYBLE_ERROR_NTF_DISABLED;
    }
    else
    {
        CYBLE_GATTS_HANDLE_VALUE_NTF_T ntfParam;
        
        /* Fill all fields of write request structure ... */
        ntfParam.attrHandle = cyBle_cgmss.charInfo[charIndex].charHandle; 
        ntfParam.value.val = attrValue;
        ntfParam.value.len = attrSize;
        
        /* Send notification to client using previously filled structure */
        apiResult = CyBle_GattsNotification(connHandle, &ntfParam);
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmssSendIndication
***************************************************************************//**
* 
*  Sends an indication of the specified characteristic to the client device, as
*  defined by the charIndex value.
*  
*  On enabling indication successfully, if the GATT server has an updated value to be 
*  indicated to the GATT Client, it sends out a 'Handle Value Indication' which
*  results in CYBLE_EVT_CGMSC_INDICATION or CYBLE_EVT_GATTC_HANDLE_VALUE_IND (if 
*  service specific callback function is not registered) event at the GATT Client's end.
*
*  \param connHandle: The connection handle which consists of the device ID and ATT 
*               connection ID.
*  \param charIndex: The index of the service characteristic.
*  \param attrSize: The size of the characteristic value attribute.
*  \param attrValue: The pointer to the Characteristic value data that should be sent 
*               to Client device.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*   * CYBLE_ERROR_OK - The request handled successfully
*   * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*   * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this 
*                                      characteristic.
*   * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - An optional characteristic is absent.
*   * CYBLE_ERROR_INVALID_STATE - Connection with the client is not established.
*   * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*   * CYBLE_ERROR_IND_DISABLED - Indication is not enabled by the client.
*
* \events
*  In case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the CGMS service-specific callback is registered 
*      (with CyBle_CgmsRegisterAttrCallback):
*  * CYBLE_EVT_CGMSS_INDICATION_CONFIRMED - in case if the indication is
*                                successfully delivered to the peer device.
*  .
*   Otherwise (if the CGMS service-specific callback is not registered):
*  * CYBLE_EVT_GATTS_HANDLE_VALUE_CNF - in case if the indication is
*                                successfully delivered to the peer device.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmssSendIndication(CYBLE_CONN_HANDLE_T connHandle,
                    CYBLE_CGMS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Send indication if it is enabled and connected */
    if(CYBLE_STATE_CONNECTED != CyBle_GetState())
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if(charIndex >= CYBLE_CGMS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(cyBle_cgmss.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD] == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
        apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
    }
    else if(!CYBLE_IS_INDICATION_ENABLED(cyBle_cgmss.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD]))
    {
        apiResult = CYBLE_ERROR_IND_DISABLED;
    }
    else
    {
        CYBLE_GATTS_HANDLE_VALUE_IND_T indParam;
        
        /* Fill all fields of write request structure ... */
        indParam.attrHandle = cyBle_cgmss.charInfo[charIndex].charHandle; 
        indParam.value.val = attrValue;
        indParam.value.len = attrSize;
        
        /* Send notification to client using previously filled structure */
        apiResult = CyBle_GattsIndication(connHandle, &indParam);
        
        if(apiResult == CYBLE_ERROR_OK)
        {
            /* Save handle to support service specific value confirmation response from client */
            cyBle_cgmssReqHandle = indParam.attrHandle;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmssConfirmationEventHandler
***************************************************************************//**
* 
*  Handles a Value Confirmation request event from the BLE stack.
* 
*  \param eventParam: The pointer to a structure of type CYBLE_CONN_HANDLE_T
* 
******************************************************************************/
void CyBle_CgmssConfirmationEventHandler(const CYBLE_CONN_HANDLE_T *eventParam)
{
    if((NULL != CyBle_CgmsApplCallback) 
        && (cyBle_cgmss.charInfo[CYBLE_CGMS_RACP].charHandle == cyBle_cgmssReqHandle))
    {   
        CYBLE_CGMS_CHAR_VALUE_T locCharIndex;
        
        for(locCharIndex.charIndex = CYBLE_CGMS_RACP;
                    locCharIndex.charIndex < CYBLE_CGMS_CHAR_COUNT; locCharIndex.charIndex++)
	    {
            if(cyBle_cgmss.charInfo[locCharIndex.charIndex].charHandle == cyBle_cgmssReqHandle)
	        {
                cyBle_cgmssReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                locCharIndex.connHandle = *eventParam;
                locCharIndex.value = NULL;
                
                if(locCharIndex.charIndex == CYBLE_CGMS_RACP)
                {
                    cyBle_cgmsFlag &= (uint8) ~CYBLE_CGMS_FLAG_PROCESS;
                }
                
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSS_INDICATION_CONFIRMED, &locCharIndex);
            }
        }
    }
}


/******************************************************************************
* Function Name: CyBle_CgmssWriteEventHandler
***************************************************************************//**
* 
*  Handles a Write Request event. Calls the registered CGMS application 
*  callback function.
* 
* Note: Writing the attribute into GATT DB (if needed) is on the user's responsibility,
*  after the characteristic content check in the registered CGMS application 
*  callback function.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  CYBLE_GATT_ERR_CODE_T - An API result state if the API succeeded 
*  (CYBLE_GATT_ERR_NONE) or failed with error codes:
*   * CYBLE_GATTS_ERR_PROCEDURE_ALREADY_IN_PROGRESS
*   * CYBLE_GATTS_ERR_CCCD_IMPROPERLY_CONFIGURED
* 
******************************************************************************/
CYBLE_GATT_ERR_CODE_T CyBle_CgmssWriteEventHandler(CYBLE_GATTS_WRITE_REQ_PARAM_T *eventParam)
{
    CYBLE_CGMS_CHAR_VALUE_T locCharValue;
    locCharValue.gattErrorCode = CYBLE_GATT_ERR_NONE;
    
    if(CyBle_CgmsApplCallback != NULL)
    {
        locCharValue.connHandle = eventParam->connHandle;
	
	    for(locCharValue.charIndex = CYBLE_CGMS_CGMT;
                    locCharValue.charIndex < CYBLE_CGMS_CHAR_COUNT; locCharValue.charIndex++)
	    {
            if(eventParam->handleValPair.attrHandle == cyBle_cgmss.charInfo[locCharValue.charIndex].charHandle)
	        {   
                locCharValue.value = &eventParam->handleValPair.value;
                
                if(locCharValue.charIndex == CYBLE_CGMS_RACP)
                {
                    if(CYBLE_CGMS_IS_PROCEDURE_IN_PROGRESS)
                    {
                        if(eventParam->handleValPair.value.val[0u] == CYBLE_CGMS_RACP_OPCODE_ABORT)
                        {
                            cyBle_cgmsFlag &= (uint8) ~CYBLE_CGMS_FLAG_PROCESS;
                        }
                        else
                        {
                            locCharValue.gattErrorCode = CYBLE_GATT_ERR_PROCEDURE_ALREADY_IN_PROGRESS;
                        }
                    }
                    else if(!CYBLE_IS_INDICATION_ENABLED(cyBle_cgmss.charInfo[CYBLE_CGMS_RACP].descrHandle[CYBLE_CGMS_CCCD]))
                    {
                        locCharValue.gattErrorCode = CYBLE_GATT_ERR_CCCD_IMPROPERLY_CONFIGURED;
                    }
                    else
                    {
                        cyBle_cgmsFlag |= CYBLE_CGMS_FLAG_PROCESS;
                    }
                }
                else
                {
                    /* CYBLE_CGMS_SOCP or CYBLE_CGMS_SSTM */
                }
                
                if(locCharValue.gattErrorCode == CYBLE_GATT_ERR_NONE)
    	        {
                    CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSS_WRITE_CHAR, &locCharValue);
                }
                
                if(locCharValue.gattErrorCode == CYBLE_GATT_ERR_NONE)
    	        {
                    locCharValue.gattErrorCode = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair,
                             0u, &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
                }
    			
                /* Clear callback flag indicating that request was handled */
    			cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                locCharValue.charIndex = CYBLE_CGMS_CHAR_COUNT; /* instead of break */
    	    }
    	    else if(eventParam->handleValPair.attrHandle == cyBle_cgmss.charInfo[locCharValue.charIndex].descrHandle[CYBLE_CGMS_CCCD])
            {
                locCharValue.value = NULL;
                locCharValue.gattErrorCode = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair,
                             0u, &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
                if(locCharValue.gattErrorCode == CYBLE_GATT_ERR_NONE)
                {
                    uint32 eventCode;
                    
                    if(locCharValue.charIndex == CYBLE_CGMS_CGMT)
                    {
                        if(CYBLE_IS_NOTIFICATION_ENABLED_IN_PTR(eventParam->handleValPair.value.val))
                        {
                            eventCode = (uint32)CYBLE_EVT_CGMSS_NOTIFICATION_ENABLED;
                        }
                        else
                        {
                            eventCode = (uint32)CYBLE_EVT_CGMSS_NOTIFICATION_DISABLED;
                        }
                    }
                    else
                    {
                        if(CYBLE_IS_INDICATION_ENABLED_IN_PTR(eventParam->handleValPair.value.val))
                        {
                            eventCode = (uint32)CYBLE_EVT_CGMSS_INDICATION_ENABLED;
                        }
                        else
                        {
                            eventCode = (uint32)CYBLE_EVT_CGMSS_INDICATION_DISABLED;
                        }
                    }
                    
                    CyBle_CgmsApplCallback(eventCode, &locCharValue);
                
                #if((CYBLE_GAP_ROLE_PERIPHERAL || CYBLE_GAP_ROLE_CENTRAL) && \
                    (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES))
                    /* Set flag to store bonding data to flash */
                    if(cyBle_peerBonding == CYBLE_GAP_BONDING)
                    {
                        cyBle_pendingFlashWrite |= CYBLE_PENDING_CCCD_FLASH_WRITE_BIT;
                    }
                #endif /* (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES) */
				}
                
                /* Clear callback flag indicating that request was handled */
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                locCharValue.charIndex = CYBLE_CGMS_CHAR_COUNT; /* instead of break */
			}
            else
            {
                /* Nothing else */    
            }
        }
    }

    return (locCharValue.gattErrorCode);
}

#endif /* CYBLE_CGMS_SERVER */

#ifdef CYBLE_CGMS_CLIENT


/******************************************************************************
* Function Name: CyBle_CgmscSetCharacteristicValue
***************************************************************************//**
* 
*  This function is used to write the characteristic (which is identified by
*  charIndex) value attribute in the server. As a result a Write Request is 
*  sent to the GATT Server and on successful execution of the request on the 
*  Server side the CYBLE_EVT_CGMSS_WRITE_CHAR events is generated.
*  On successful request execution on the Server side the Write Response is 
*  sent to the Client.
* 
*  \param connHandle: The connection handle.
*  \param charIndex: The index of a service characteristic.
*  \param attrSize: The size of the characteristic value attribute.
*  \param attrValue: The pointer to the characteristic value data that should be 
*               sent to the server device.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_INVALID_STATE - Connection with the server is not established.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                               the particular characteristic.
*  * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this
*                                     characteristic.
*
* \events
*  In case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the CGMS service-specific callback is registered 
*      (with CyBle_CgmsRegisterAttrCallback):
*  * CYBLE_EVT_CGMSC_WRITE_CHAR_RESPONSE - in case if the requested attribute is
*                                successfully wrote on the peer device,
*                                the details (char index, etc.) are 
*                                provided with event parameter structure
*                                of type CYBLE_CGMS_CHAR_VALUE_T.
*  .
*   Otherwise (if the CGMS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_WRITE_RSP - in case if the requested attribute is 
*                                successfully wrote on the peer device.
*  * CYBLE_EVT_GATTC_ERROR_RSP - in case if there some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with event parameters 
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmscSetCharacteristicValue(CYBLE_CONN_HANDLE_T connHandle,
                                                        CYBLE_CGMS_CHAR_INDEX_T charIndex,
                                                            uint8 attrSize, uint8 * attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if(charIndex >= CYBLE_CGMS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
	else if(cyBle_cgmsc.charInfo[charIndex].valueHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else if((CYBLE_CHAR_PROP_WRITE & cyBle_cgmsc.charInfo[charIndex].properties) == 0u)
    {
        apiResult = CYBLE_ERROR_INVALID_OPERATION;
    }
    else
    {
        CYBLE_GATTC_WRITE_REQ_T writeReqParam;
        
        writeReqParam.attrHandle = cyBle_cgmsc.charInfo[charIndex].valueHandle;
        writeReqParam.value.val = attrValue;
        writeReqParam.value.len = attrSize;

        apiResult = CyBle_GattcWriteCharacteristicValue(connHandle, &writeReqParam);
        if(apiResult == CYBLE_ERROR_OK)
        {
            cyBle_cgmscReqHandle = cyBle_cgmsc.charInfo[charIndex].valueHandle;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmscGetCharacteristicValue
***************************************************************************//**
* 
*  This function is used to read the characteristic Value from a server
*  identified by charIndex.
* 
*  \param connHandle: The connection handle.
*  \param charIndex: The index of the service characteristic.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The read request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                               the particular characteristic.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_INVALID_STATE - Connection with the server is not established.
*  * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this 
*                                     characteristic.
*
* \events
*  In case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the CGMS service-specific callback is registered 
*      (with CyBle_CgmsRegisterAttrCallback):
*  * CYBLE_EVT_CGMSC_READ_CHAR_RESPONSE - in case if the requested attribute is
*                                successfully wrote on the peer device,
*                                the details (char index , value, etc.) are 
*                                provided with event parameter structure
*                                of type CYBLE_CGMS_CHAR_VALUE_T.
*  .
*   Otherwise (if the CGMS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_READ_RSP - in case if the requested attribute is 
*                                successfully read on the peer device,
*                                the details (handle, value, etc.) are 
*                                provided with event parameters 
*                                structure (CYBLE_GATTC_READ_RSP_PARAM_T).
*  * CYBLE_EVT_GATTC_ERROR_RSP - in case if there some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with event parameters 
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmscGetCharacteristicValue(CYBLE_CONN_HANDLE_T connHandle, CYBLE_CGMS_CHAR_INDEX_T charIndex)
{
    CYBLE_API_RESULT_T apiResult;

    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if(charIndex >= CYBLE_CGMS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
	else if(cyBle_cgmsc.charInfo[charIndex].valueHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else if((CYBLE_CHAR_PROP_READ & cyBle_cgmsc.charInfo[charIndex].properties) == 0u)
    {
        apiResult = CYBLE_ERROR_INVALID_OPERATION;
    }
    else
    {
        apiResult = CyBle_GattcReadCharacteristicValue(connHandle, cyBle_cgmsc.charInfo[charIndex].valueHandle);
        if(apiResult == CYBLE_ERROR_OK)
        {
            cyBle_cgmscReqHandle = cyBle_cgmsc.charInfo[charIndex].valueHandle;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmscSetCharacteristicDescriptor
***************************************************************************//**
* 
*  Sets the Characteristic Descriptor of the specified characteristic.
*
*  Internally, Write Request is sent to the GATT Server and on successful 
*  execution of the request on the Server side the following events can be 
*  generated: 
*  * CYBLE_EVT_CGMSS_INDICATION_ENABLED 
*  * CYBLE_EVT_CGMSS_INDICATION_DISABLED
*  * CYBLE_EVT_CGMSS_NOTIFICATION_ENABLED 
*  * CYBLE_EVT_CGMSS_NOTIFICATION_DISABLED
* 
*  \param connHandle: The connection handle.
*  \param charIndex: The index of a service characteristic.
*  \param descrIndex: The index of a service characteristic descriptor.
*  \param attrSize: The size of the characteristic descriptor value attribute.
*  \param attrValue: The pointer to the characteristic descriptor value data that should 
*               be sent to the server device.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_INVALID_STATE - The state is not valid.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                               the particular characteristic.
*  * CYBLE_ERROR_INVALID_OPERATION - This operation is not permitted on 
*                                     the specified attribute.
*
* \events
*  In case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the CGMS service-specific callback is registered 
*      (with CyBle_CgmsRegisterAttrCallback):
*  * CYBLE_EVT_CGMSC_WRITE_DESCR_RESPONSE - in case if the requested attribute is
*                                successfully wrote on the peer device,
*                                the details (char index, descr index etc.) are 
*                                provided with event parameter structure
*                                of type CYBLE_CGMS_DESCR_VALUE_T.
*  .
*   Otherwise (if the CGMS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_WRITE_RSP - in case if the requested attribute is 
*                                successfully wrote on the peer device.
*  * CYBLE_EVT_GATTC_ERROR_RSP - in case if there some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with event parameters 
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmscSetCharacteristicDescriptor(CYBLE_CONN_HANDLE_T connHandle, 
    CYBLE_CGMS_CHAR_INDEX_T charIndex, CYBLE_CGMS_DESCR_INDEX_T descrIndex, uint8 attrSize, uint8 * attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if((charIndex >= CYBLE_CGMS_CHAR_COUNT)
         || (descrIndex >= CYBLE_CGMS_DESCR_COUNT)
         || (attrSize != CYBLE_CCCD_LEN))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(cyBle_cgmsc.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD] == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else
    {
        CYBLE_GATTC_WRITE_REQ_T writeReqParam;
        
        /* Fill all fields of write request structure ... */
        writeReqParam.attrHandle = cyBle_cgmsc.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD];
        writeReqParam.value.val = attrValue;
        writeReqParam.value.len = CYBLE_CCCD_LEN;

        /* ... and send request to server device. */
        apiResult = CyBle_GattcWriteCharacteristicDescriptors(connHandle, &writeReqParam);
        if(apiResult == CYBLE_ERROR_OK)
        {
            /* Save handle to support service specific read response from device */
            cyBle_cgmscReqHandle = writeReqParam.attrHandle;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmscGetCharacteristicDescriptor
***************************************************************************//**
* 
*  Gets the characteristic descriptor of the specified characteristic.
* 
*  \param connHandle: The connection handle.
*  \param charIndex: The index of a service characteristic.
*  \param descrIndex: The index of the service characteristic descriptor.
* 
* \return
*  The return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_INVALID_STATE - The state is not valid.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                               the particular descriptor.
*  * CYBLE_ERROR_INVALID_OPERATION - This operation is not permitted on 
*                                     the specified attribute.
*
* \events
*  In case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*  If the CGMS service-specific callback is registered 
*      (with CyBle_CgmsRegisterAttrCallback):
*  * CYBLE_EVT_CGMSC_READ_DESCR_RESPONSE - in case if the requested attribute is
*                                successfully wrote on the peer device,
*                                the details (char index, descr index, value, etc.) 
*                                are provided with event parameter structure
*                                of type CYBLE_CGMS_DESCR_VALUE_T. 
*  .
*  Otherwise (if the CGMS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_READ_RSP - in case if the requested attribute is 
*                                successfully read on the peer device,
*                                the details (handle, value, etc.) are 
*                                provided with event parameters 
*                                structure (CYBLE_GATTC_READ_RSP_PARAM_T).
*  * CYBLE_EVT_GATTC_ERROR_RSP - in case if there some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with event parameters 
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_CgmscGetCharacteristicDescriptor(CYBLE_CONN_HANDLE_T connHandle,
                       CYBLE_CGMS_CHAR_INDEX_T charIndex, CYBLE_CGMS_DESCR_INDEX_T descrIndex)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if((charIndex >= CYBLE_CGMS_CHAR_COUNT) || (descrIndex >= CYBLE_CGMS_DESCR_COUNT))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(cyBle_cgmsc.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD] == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else
    {
        apiResult = CyBle_GattcReadCharacteristicDescriptors(connHandle, cyBle_cgmsc.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD]);
        if(apiResult == CYBLE_ERROR_OK)
        {
            cyBle_cgmscReqHandle = cyBle_cgmsc.charInfo[charIndex].descrHandle[CYBLE_CGMS_CCCD];
        }
    }
    
    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_CgmscDiscoverCharacteristicsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a CYBLE_EVT_GATTC_READ_BY_TYPE_RSP
*  event. Based on the service UUID, an appropriate data structure is populated
*  using the data received as part of the callback.
* 
*  \param discCharInfo: The pointer to a characteristic information structure.
* 
******************************************************************************/
void CyBle_CgmscDiscoverCharacteristicsEventHandler(CYBLE_DISC_CHAR_INFO_T *discCharInfo)
{
    /* CGM Service characteristics UUIDs */
    static const CYBLE_UUID16 cyBle_cgmscCharUuid[CYBLE_CGMS_CHAR_COUNT] =
    {
        CYBLE_UUID_CHAR_CGM_MEASUREMENT,
        CYBLE_UUID_CHAR_CGM_FEATURE,
        CYBLE_UUID_CHAR_CGM_STATUS,
        CYBLE_UUID_CHAR_CGM_SESSION_START_TIME,
        CYBLE_UUID_CHAR_CGM_SESSION_RUN_TIME,
        CYBLE_UUID_CHAR_RACP,
        CYBLE_UUID_CHAR_CGM_SOCP
    };
    static CYBLE_GATT_DB_ATTR_HANDLE_T *cgmsLastEndHandle = NULL;
    uint8 i;
    
    /* Update last characteristic endHandle to declaration handle of this characteristic */
    if(cgmsLastEndHandle != NULL)
    {
        *cgmsLastEndHandle = discCharInfo->charDeclHandle - 1u;
        cgmsLastEndHandle = NULL;
    }
    
    for(i = 0u; i < (uint8) CYBLE_CGMS_CHAR_COUNT; i++)
    {
        if(cyBle_cgmscCharUuid[i] == discCharInfo->uuid.uuid16)
        {
            if(cyBle_cgmsc.charInfo[i].valueHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
            {
                cyBle_cgmsc.charInfo[i].valueHandle = discCharInfo->valueHandle;
                cyBle_cgmsc.charInfo[i].properties = discCharInfo->properties;
                cgmsLastEndHandle = &cyBle_cgmsc.charInfo[i].endHandle;
            }
            else
            {
                CyBle_ApplCallback((uint32)CYBLE_EVT_GATTC_CHAR_DUPLICATION, &discCharInfo->uuid);
            }
        }
    }
    
    /* Init characteristic endHandle to Service endHandle.
       Characteristic endHandle will be updated to declaration
       Handler of following characteristic,
       in following characteristic discovery procedure. */
    if(cgmsLastEndHandle != NULL)
    {
        *cgmsLastEndHandle = cyBle_serverInfo[CYBLE_SRVI_CGMS].range.endHandle;
    }
}


/******************************************************************************
* Function Name: CyBle_CgmscDiscoverCharDescriptorsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a CYBLE_EVT_GATTC_READ_BY_TYPE_RSP
*  event. Based on the service UUID, an appropriate data structure is populated
*  using the data received as part of the callback.
* 
*  \param discCharInfo: The pointer to a characteristic information structure.
* 
******************************************************************************/
void CyBle_CgmscDiscoverCharDescriptorsEventHandler(CYBLE_DISC_DESCR_INFO_T *discDescrInfo)
{
    if(discDescrInfo->uuid.uuid16 == CYBLE_UUID_CHAR_CLIENT_CONFIG)
    {
        uint8 charIdx = cyBle_disCount - CYBLE_SCDI_CGMS_CGMT;
        if(charIdx > ((uint8) CYBLE_CGMS_CGMT))
        {
            /* charIdx for RACP is 5 and for SOCP it is 6 */
            charIdx += (uint8)(CYBLE_CGMS_RACP - 1u);
        }
        
        if(cyBle_cgmsc.charInfo[charIdx].descrHandle[CYBLE_CGMS_CCCD] == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
        {
            cyBle_cgmsc.charInfo[charIdx].descrHandle[CYBLE_CGMS_CCCD] = discDescrInfo->descrHandle;
        }
        else    /* Duplication of descriptor */
        {
            CyBle_ApplCallback((uint32)CYBLE_EVT_GATTC_DESCR_DUPLICATION, &discDescrInfo->uuid);
        }
    }
}


/******************************************************************************
* Function Name: CyBle_CgmscNotificationEventHandler
***************************************************************************//**
* 
*  Handles a Notification event.
* 
*  \param eventParam: The pointer to a data structure specified by the event.
* 
******************************************************************************/
void CyBle_CgmscNotificationEventHandler(CYBLE_GATTC_HANDLE_VALUE_NTF_PARAM_T *eventParam)
{
    if(NULL != CyBle_CgmsApplCallback)
    {
        CYBLE_CGMS_CHAR_VALUE_T locCharValue;
        
        if(cyBle_cgmsc.charInfo[CYBLE_CGMS_CGMT].valueHandle == eventParam->handleValPair.attrHandle)
        {
            locCharValue.charIndex = CYBLE_CGMS_CGMT;
            locCharValue.connHandle = eventParam->connHandle;
            locCharValue.value = &eventParam->handleValPair.value;

            CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSC_NOTIFICATION, &locCharValue);
            cyBle_eventHandlerFlag &= (uint8) ~CYBLE_CALLBACK;
        }
    }
}


/******************************************************************************
* Function Name: CyBle_CgmscIndicationEventHandler
***************************************************************************//**
* 
*  Handles an Indication event.
* 
*  \param eventParam:  The pointer to a data structure specified by the event.
* 
******************************************************************************/
void CyBle_CgmscIndicationEventHandler(CYBLE_GATTC_HANDLE_VALUE_IND_PARAM_T *eventParam)
{
    if(NULL != CyBle_CgmsApplCallback)
    {
        CYBLE_CGMS_CHAR_VALUE_T locCharValue;
        locCharValue.charIndex = CYBLE_CGMS_RACP;
        
        while((cyBle_cgmsc.charInfo[locCharValue.charIndex].valueHandle != 
            eventParam->handleValPair.attrHandle) && (locCharValue.charIndex < CYBLE_CGMS_CHAR_COUNT))
        {
            locCharValue.charIndex++;
        }

        if(locCharValue.charIndex < CYBLE_CGMS_CHAR_COUNT)
        {
            locCharValue.connHandle = eventParam->connHandle;       
            locCharValue.value = &eventParam->handleValPair.value;
            cyBle_eventHandlerFlag &= (uint8) ~CYBLE_CALLBACK;
            CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSC_INDICATION, &locCharValue);
        }
    }
}


/******************************************************************************
* Function Name: CyBle_CgmscReadResponseEventHandler
***************************************************************************//**
* 
*  Handles a Read Response event.
* 
*  \param eventParam: The pointer to the data structure.
* 
******************************************************************************/
void CyBle_CgmscReadResponseEventHandler(CYBLE_GATTC_READ_RSP_PARAM_T *eventParam)
{
    if((NULL != CyBle_CgmsApplCallback) && (CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE != cyBle_cgmscReqHandle))
    {
        CYBLE_CGMS_CHAR_INDEX_T charIdx;
        uint8 flag = 0u;
        
        for(charIdx = CYBLE_CGMS_CGMT; (charIdx < CYBLE_CGMS_CHAR_COUNT) && (flag == 0u); charIdx++)
        {
            if(cyBle_cgmsc.charInfo[charIdx].valueHandle == cyBle_cgmscReqHandle)
            {
                CYBLE_CGMS_CHAR_VALUE_T locCharValue;
                
                locCharValue.connHandle = eventParam->connHandle;
                locCharValue.charIndex = charIdx;
                locCharValue.value = &eventParam->value;
                
                cyBle_cgmscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSC_READ_CHAR_RESPONSE, &locCharValue);
                flag = 1u; /* instead of break */
            }
            else if(cyBle_cgmsc.charInfo[charIdx].descrHandle[CYBLE_CGMS_CCCD] == cyBle_cgmscReqHandle)
            {
                CYBLE_CGMS_DESCR_VALUE_T locDescrValue;
                
                locDescrValue.connHandle = eventParam->connHandle;
                locDescrValue.charIndex = charIdx;
                locDescrValue.descrIndex = CYBLE_CGMS_CCCD;
                locDescrValue.value = &eventParam->value;

                cyBle_cgmscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSC_READ_DESCR_RESPONSE, &locDescrValue);
                flag = 1u; /* instead of break */
            }
            else
            {
                /* nothing else */
            }
        }
    }
}


/******************************************************************************
* Function Name: CyBle_CgmscWriteResponseEventHandler
***************************************************************************//**
* 
*  Handles a Write Response event.
* 
*  \param eventParam: The pointer to a data structure specified by the event.
* 
******************************************************************************/
void CyBle_CgmscWriteResponseEventHandler(const CYBLE_CONN_HANDLE_T *eventParam)
{
    if((NULL != CyBle_CgmsApplCallback) && (CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE != cyBle_cgmscReqHandle))
    {
        CYBLE_CGMS_CHAR_INDEX_T charIdx;
        uint8 flag = 0u;
        
        for(charIdx = CYBLE_CGMS_CGMT; (charIdx < CYBLE_CGMS_CHAR_COUNT) && (flag == 0u); charIdx++)
        {
            if(cyBle_cgmsc.charInfo[charIdx].valueHandle == cyBle_cgmscReqHandle)
            {
                CYBLE_CGMS_CHAR_VALUE_T locCharValue;
                
                locCharValue.connHandle = *eventParam;
                locCharValue.charIndex = charIdx;
                locCharValue.value = NULL;
                
                cyBle_cgmscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSC_WRITE_CHAR_RESPONSE, &locCharValue);
                flag = 1u; /* instead of break */
            }
            else if(cyBle_cgmsc.charInfo[charIdx].descrHandle[CYBLE_CGMS_CCCD] == cyBle_cgmscReqHandle)
            {
                CYBLE_CGMS_DESCR_VALUE_T locDescrValue;
                
                locDescrValue.connHandle = *eventParam;
                locDescrValue.charIndex = charIdx;
                locDescrValue.descrIndex = CYBLE_CGMS_CCCD;
                locDescrValue.value = NULL;

                cyBle_cgmscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                CyBle_CgmsApplCallback((uint32)CYBLE_EVT_CGMSC_WRITE_DESCR_RESPONSE, &locDescrValue);
                flag = 1u; /* instead of break */
            }
            else
            {
                /* nothing else */
            }
        }
    }
}


/******************************************************************************
* Function Name: CyBle_CgmscErrorResponseEventHandler
***************************************************************************//**
* 
*  Handles an Error Response event.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
******************************************************************************/
void CyBle_CgmscErrorResponseEventHandler(const CYBLE_GATTC_ERR_RSP_PARAM_T *eventParam)
{
    if((eventParam != NULL) && (eventParam->attrHandle == cyBle_cgmscReqHandle))
    {
        cyBle_cgmscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
    }
}


#endif /* CYBLE_CGMS_CLIENT */


/* [] END OF FILE */
