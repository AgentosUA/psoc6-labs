/*******************************************************************************
* File Name: CapSense_TMG.c
* Version 2.0
*
* Description:
*  This file provides the source code of the API for the CapSense TMG component.
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_TMG.h"


/*******************************************************************************
* Function Name: CapSense_TMG_DecodeAllGestures
********************************************************************************
*
* Summary:
*  Decodes all enabled gestures in the customizer and returns the detected
*  gesture code.
*  CapSense_TMG_InitGestures and CapSense_TMG_TimerEnableInt has to be
*  called once prior calling this or any other API for gesture decoding.
*
* Parameters:
*  touchNumber: Number of fingers on the trackpad. Valid range 0-2.
*  currentTimestamp : Current timestamp value.
*  pos: Pointer to structure with coordinates of touches.
*
* Return:
*  Detected gesture code.
*
*******************************************************************************/
uint32_t CapSense_TMG_DecodeAllGestures(uint32_t touchNumber, uint32_t currentTimestamp, const CapSense_TMG_POSITION_STRUCT *pos)
{
    uint32_t gestureID = CapSense_TMG_NO_GESTURE;
    #if(0u != CapSense_TMG_GESTURES_ENABLED)
        /* Variable for detected click gestures */
        uint32_t clickGesture = CapSense_TMG_NO_GESTURE;

        /* Variable for detected single touch gestures */
        uint32_t stGesture = CapSense_TMG_NO_GESTURE;

        /* Variable for detected double touch gestures */
        uint32_t dtGesture = CapSense_TMG_NO_GESTURE;

        #if (CapSense_TMG_ROTATE_ENABLED != 0u)
            static uint32_t rotationActive = 0u;
        #endif /* (CapSense_TMG_ROTATE_ENABLED != 0u) */

        #if (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u)
            static uint32_t edgeTimeoutStamp = 0u;
            uint32_t deltaTimeoutStamp = 0u;
        #endif /* (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u) */

        #if ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && ((CapSense_TMG_CLICKS_ENABLED == 1u) ||\
                                                             (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                             (CapSense_TMG_ROTATE_ENABLED == 1u)))
            static uint32_t edgeSwipeActive = 0u;
        #endif /* ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && ((CapSense_TMG_CLICKS_ENABLED == 1u) ||\
                                                                   (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                                   (CapSense_TMG_ROTATE_ENABLED == 1u))) */

        #if ((CapSense_TMG_CLICKS_ENABLED == 1u) && ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) ||\
                                                         (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                         (CapSense_TMG_ROTATE_ENABLED == 1u)))
            static uint32_t clickAndDragActive = 0u;
        #endif /* ((CapSense_TMG_CLICKS_ENABLED == 1u) && ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) ||\
                                                               (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                               (CapSense_TMG_ROTATE_ENABLED == 1u))) */

        #if (CapSense_TMG_EDGE_SWIPE_ENABLED == 1u)
            uint32_t edgeSwipeGesture = CapSense_TMG_NO_GESTURE;
        #endif /* (CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) */

        #if ((CapSense_TMG_CLICKS_ENABLED != 0u) || (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u))
            clickGesture = Gesture_DecodeAllClickGestures((uint8_t)touchNumber, currentTimestamp, pos);
        #endif /* ((CapSense_TMG_CLICKS_ENABLED != 0u) || (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u)) */

        #if (CapSense_TMG_CLICKS_ENABLED != 0u)
            gestureID = clickGesture;
            #if ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) || (CapSense_TMG_ST_SCROLLS_ENABLED == 1u))
            if (clickGesture == CapSense_TMG_CLICK_AND_DRAG)
            {
                clickAndDragActive = 1u;
            }
            #endif /* ((CapSense_TMG_CLICKS_ENABLED == 1u) || (CapSense_TMG_ST_SCROLLS_ENABLED == 1u)) */
        #endif /* (CapSense_TMG_CLICKS_ENABLED != 0u) */

        #if (CapSense_TMG_ROTATE_ENABLED == 1u)
            stGesture = Gesture_DecodeSTRotateGestures((uint8_t)touchNumber, currentTimestamp, pos);

            #if ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) || (CapSense_TMG_CLICKS_ENABLED == 1u))
                #if ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && (CapSense_TMG_CLICKS_ENABLED == 1u))
                    if ((clickAndDragActive == 1u) || (edgeSwipeActive == 1u))
                #elif (CapSense_TMG_CLICKS_ENABLED == 1u)
                    if (clickAndDragActive == 1u)
                #elif (CapSense_TMG_EDGE_SWIPE_ENABLED == 1u)
                    if (edgeSwipeActive == 1u)
                #endif /* ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && (CapSense_TMG_CLICKS_ENABLED == 1u)) */
                {
                    stGesture = CapSense_TMG_NO_GESTURE;
                }
            #endif /* ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) || (CapSense_TMG_CLICKS_ENABLED == 1u)) */
            if ((stGesture == CapSense_TMG_ROTATE_CW) || (stGesture == CapSense_TMG_ROTATE_CCW))
            {
                rotationActive = CapSense_TMG_ROTATE_TO_OTHER_DEBOUNCE;
            }
            else
            {
                if (rotationActive > 0u)
                {
                    rotationActive--;
                }
            }

            if (((stGesture == CapSense_TMG_NO_GESTURE)||(stGesture == CapSense_TMG_TOUCHDOWN) \
                                            ||(stGesture == CapSense_TMG_LIFT_OFF))&&(rotationActive == 0u))
        #else
            if ((stGesture == CapSense_TMG_NO_GESTURE)||(stGesture == CapSense_TMG_TOUCHDOWN) \
                                            ||(stGesture == CapSense_TMG_LIFT_OFF))
        #endif /* (CapSense_TMG_ROTATE_ENABLED == 1u) */
        {
            #if (CapSense_TMG_ST_SCROLLS_ENABLED == 1u)
                #if ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && (CapSense_TMG_CLICKS_ENABLED == 1u))
                    if ((clickAndDragActive == 0u)&&(edgeSwipeActive == 0u))
                #elif (CapSense_TMG_CLICKS_ENABLED == 1u)
                    if (clickAndDragActive == 0u)
                #elif (CapSense_TMG_EDGE_SWIPE_ENABLED == 1u)
                    if (edgeSwipeActive == 0u)
                #else
                    if (1u == 1u)
                #endif /* ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && (CapSense_TMG_CLICKS_ENABLED == 1u)) */
                {
                    stGesture = Gesture_DecodeSTScrollGestures((uint8_t)touchNumber, currentTimestamp, pos);
                }
            #elif (CapSense_TMG_FLICKS_ENABLED == 1u)
                stGesture = Gesture_DecodeFlickGestures((uint8_t)touchNumber, currentTimestamp, pos);
            #endif /* (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) */
        }

        #if (CapSense_TMG_EDGE_SWIPE_ENABLED == 1u)
            edgeSwipeGesture = Gesture_DecodeEdgeSwipeGestures((uint8_t)touchNumber, currentTimestamp, pos);

            #if (CapSense_TMG_ROTATE_ENABLED == 1u)
                if (((edgeSwipeGesture != CapSense_TMG_NO_GESTURE) && \
                    (edgeSwipeGesture != CapSense_TMG_TOUCHDOWN) && (edgeSwipeGesture != CapSense_TMG_LIFT_OFF)) \
                                                                                            && (rotationActive == 0u))
            #else
                if ((edgeSwipeGesture != CapSense_TMG_NO_GESTURE) && \
                    (edgeSwipeGesture != CapSense_TMG_TOUCHDOWN) && (edgeSwipeGesture != CapSense_TMG_LIFT_OFF))
            #endif /* (CapSense_TMG_ROTATE_ENABLED == 1u) */
            {
                stGesture = edgeSwipeGesture;
                #if ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && ((CapSense_TMG_CLICKS_ENABLED == 1u) ||\
                                                                     (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                                     (CapSense_TMG_ROTATE_ENABLED == 1u)))
                    edgeSwipeActive = 1u;
                #endif /* ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && ((CapSense_TMG_CLICKS_ENABLED == 1u) ||\
                                                                           (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                                           (CapSense_TMG_ROTATE_ENABLED == 1u))) */
            }
        #endif /* (CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) */

        if ((stGesture != CapSense_TMG_NO_GESTURE)&&(stGesture != CapSense_TMG_TOUCHDOWN) \
                                            &&(stGesture != CapSense_TMG_LIFT_OFF))
        {
            gestureID = stGesture;
        }
        else if ((clickGesture == CapSense_TMG_TOUCHDOWN) || (clickGesture == CapSense_TMG_LIFT_OFF))
        {
            #if(CapSense_TMG_CLICKS_ENABLED != 0u)
                gestureID = clickGesture;
            #else
                gestureID = CapSense_TMG_NO_GESTURE;
            #endif /* (CapSense_TMG_CLICKS_ENABLED != 0u) */
        }
        else
        {
            /* Do not change gestureID */
        }

        dtGesture = CapSense_TMG_DecodeZoomGestures(touchNumber, currentTimestamp, pos);
        if ((dtGesture == CapSense_TMG_NO_GESTURE) || (dtGesture == CapSense_TMG_TOUCHDOWN) \
                                            || (dtGesture == CapSense_TMG_LIFT_OFF))
        {
            dtGesture = CapSense_TMG_DecodeDTScrollGestures(touchNumber, currentTimestamp, pos);
        }
        else
        {
            (void)CapSense_TMG_DecodeDTScrollGestures(touchNumber, currentTimestamp, pos);
        }

        if ((dtGesture != CapSense_TMG_NO_GESTURE) && (dtGesture != CapSense_TMG_TOUCHDOWN) \
                                            && (dtGesture != CapSense_TMG_LIFT_OFF))
        {
            gestureID = dtGesture;
        }

        #if (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u)
            if((gestureID >= CapSense_TMG_EDGE_SWIPE_LEFT)&&(gestureID <= CapSense_TMG_EDGE_SWIPE_BOTTOM))
            {
                edgeTimeoutStamp = currentTimestamp;
            }
        #endif /* (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u) */

        if ((clickGesture == CapSense_TMG_LIFT_OFF) || (clickGesture == CapSense_TMG_TOUCHDOWN) || \
                (gestureID == CapSense_TMG_NO_GESTURE))
        {
            #if ((CapSense_TMG_CLICKS_ENABLED == 1u) && ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) ||\
                                                             (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                             (CapSense_TMG_ROTATE_ENABLED == 1u)))
                if(0u != clickAndDragActive)
                {
                    clickAndDragActive = 0u;
                }
            #endif /* ((CapSense_TMG_CLICKS_ENABLED == 1u) && ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) ||\
                                                                   (CapSense_TMG_ST_SCROLLS_ENABLED == 1u) ||\
                                                                   (CapSense_TMG_ROTATE_ENABLED == 1u))) */

            #if (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u)
            deltaTimeoutStamp = currentTimestamp - edgeTimeoutStamp;
            if ((clickGesture == CapSense_TMG_LIFT_OFF) || (deltaTimeoutStamp >= CapSense_TMG_EDGE_SWIPE_COMPLETE_TIMEOUT))
            {
                edgeTimeoutStamp = 0u;
                #if ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && ((CapSense_TMG_CLICKS_ENABLED == 1u) || \
                                                                            (CapSense_TMG_ST_SCROLLS_ENABLED == 1u)))
                    if(0u != edgeSwipeActive)
                    {
                        edgeSwipeActive = 0u;
                    }

                #endif /* ((CapSense_TMG_EDGE_SWIPE_ENABLED == 1u) && ((CapSense_TMG_CLICKS_ENABLED == 1u) || \
                                                                            (CapSense_TMG_ST_SCROLLS_ENABLED == 1u))) */
            }
            #endif /* (CapSense_TMG_EDGE_SWIPE_ENABLED != 0u) */
        }
    #endif /* (0u != CapSense_TMG_GESTURES_ENABLED) */

    return (gestureID);
}


/*******************************************************************************
* Function Name: CapSense_TMG_ballisticsMultiplier
********************************************************************************
*
* Summary:
*  This API is to run the ballistic Multiplier.
*  CapSense_TMG_TimerEnableInt has to be called once prior calling this API.
*
* Parameters:
*   ballisticMultiplier: Pointer to the structure which contains API parameters.
*   currentTimestamp : Current timestamp value.
*   pos: Pointer to dX and dY coordinates.
*
* Return:
*  None
*
* Global Variables:
*  None
*
*******************************************************************************/
void CapSense_TMG_BallisticsMultiplier(const CapSense_TMG_BALLISTIC_MULT * ballisticMultiplier, uint32_t currentTimestamp, int16_t *pos)
{
    #if (CapSense_TMG_BALLISTICS_ENABLED == 1u)
        CapSense_TMG_BALLISTIC_MULT_INT ballisticsStrct;
        ballisticsStrct.paramStr = *ballisticMultiplier;
        ballisticsStrct.currentTimestamp = currentTimestamp;
        BallisticMultiplier(&ballisticsStrct, pos);
    #endif /* (CapSense_TMG_BALLISTICS_ENABLED == 1u) */
}


/* [] END OF FILE */
