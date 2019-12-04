/***************************************************************************//**
* \file CapSense_Gesture.c
* \version 2.0
*
* \brief
*   This file provides the source code for the centroid calculation methods
*   of the Component.
*
* \see CapSense v2.0 Datasheet
*
*//*****************************************************************************
* Copyright (2016-2017), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#include "syslib/cy_syslib.h"
#include <stddef.h>
#include "systick/cy_systick.h"
#include "CapSense_Gesture.h"

#define CapSense_CSX_ERROR_TOUCH_NUMBER     (3u)


/***********************************************************************************************************************
* Static Function Prototypes
***********************************************************************************************************************/
/**
* \cond SECTION_CYSENSE_INTERNAL
* \addtogroup group_cysense_internal
* \{
*/

#if (CapSense_ENABLE == CapSense_GES_GLOBAL_EN)
    #if(CapSense_ENABLE == CapSense_SLIDER_WIDGET_EN)
    __STATIC_INLINE void CapSense_GetCsdSldTouches(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams);
    #endif /* (CapSense_ENABLE == CapSense_SLIDER_WIDGET_EN) */

    #if(CapSense_ENABLE == CapSense_CSD_TOUCHPAD_WIDGET_EN)
    __STATIC_INLINE void CapSense_GetCsdTpTouches(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams);
    #endif /* (CapSense_ENABLE == CapSense_CSD_TOUCHPAD_WIDGET_EN) */

    #if(CapSense_ENABLE == CapSense_CSX_TOUCHPAD_WIDGET_EN)
    __STATIC_INLINE void CapSense_GetCsxTpTouches(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams);
    #endif /* (CapSense_ENABLE == CapSense_CSX_TOUCHPAD_WIDGET_EN) */
#endif /* (CapSense_ENABLE == CapSense_GES_GLOBAL_EN) */

#if (CapSense_ENABLE == CapSense_BALLISTIC_MULTIPLIER_EN)
    static uint8  CapSense_bmPrevFingerNum;
    static CapSense_TMG_POSITION_STRUCT CapSense_bmPrevFingerPos;
#endif /* (CapSense_ENABLE == CapSense_BALLISTIC_MULTIPLIER_EN) */

#if(CapSense_ENABLE == CapSense_GES_GLOBAL_EN)
    static CapSense_TOUCH_PARAM_STRUCT CapSense_touchParams;
#endif /* (CapSense_ENABLE == CapSense_GES_GLOBAL_EN) */


/** \}
* \endcond */


#if (CapSense_ENABLE == CapSense_GES_GLOBAL_EN)
    /*******************************************************************************
    * Function Name: CapSense_GetTouchParams
    ****************************************************************************//**
    *
    * \brief
    *  This function is intended to get the number of touches on touchpar or slider,
    *  position of each touch and the max number of touches which can be processed
    *  to recognize gestures.
    *
    * \details
    *  This function implements call of appropriate API to get the touch parameters
    *  depending on the type of widget, that is passed through the wdgtId nparameter.
    *  For the CSD touchpad and the CSX touchpad, function returns X and Y coordinates
    *  of each touch.
    *  For the CSD slider, functions returns the position as the X coordinate.
    *  Y coordinate for CSD sliders is always "0".
    *  This is an internal function. Calling this function from application layer is
    *  not recommended.
    *
    * \param wdgtIndex
    *  Specifies the ID number of the widget, the touch parameters needs to be
    *  returned for.
    *
    * \param touchParams
    *  Pointer to the structure which is intended to store the number of touches,
    *  position of each touch and the max number of touches which can be processed
    *  to recognize gestures for widget, that is passed through the wdgtId nparameter.
    *
    *******************************************************************************/
    void  CapSense_GetTouchParams(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams)
    {
        CapSense_WD_TYPE_ENUM widgetType;
        CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt;

        ptrFlashWdgt = &CapSense_dsFlash.wdgtArray[wdgtIndex];
        widgetType = CapSense_GET_WIDGET_TYPE(ptrFlashWdgt);

        switch(widgetType)
        {

        #if(CapSense_ENABLE == CapSense_SLIDER_WIDGET_EN)
            case CapSense_WD_LINEAR_SLIDER_E:
            case CapSense_WD_RADIAL_SLIDER_E:
                CapSense_GetCsdSldTouches(wdgtIndex, touchParams);
                break;
        #endif /* (CapSense_ENABLE == CapSense_SLIDER_WIDGET_EN) */

        #if(CapSense_ENABLE == CapSense_TOUCHPAD_WIDGET_EN)
            case CapSense_WD_TOUCHPAD_E:
                #if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN)
                    if (CapSense_SENSE_METHOD_CSD_E == CapSense_GET_SENSE_METHOD(ptrFlashWdgt))
                    {
                        CapSense_GetCsdTpTouches(wdgtIndex, touchParams);
                    }
                #endif /* #if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN) */
                #if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN)
                    if (CapSense_SENSE_METHOD_CSX_E == CapSense_GET_SENSE_METHOD(ptrFlashWdgt))
                    {
                       CapSense_GetCsxTpTouches(wdgtIndex, touchParams);
                    }
                #endif /* #if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN) */
                break;
        #endif /* (CapSense_ENABLE == CapSense_TOUCHPAD_WIDGET_EN) */

        default:
            CY_ASSERT(0 != 0);
            break;
        }
    }


    #if(CapSense_ENABLE == CapSense_SLIDER_WIDGET_EN)
        /*******************************************************************************
        * Function Name: CapSense_GetCsdSldTouches
        ****************************************************************************//**
        *
        * \brief
        *  This function is intended to get the number of touches on CSD slider, the
        *  position of each touch and the max number of touches which can be processed
        *  to recognize gestures.
        *
        * \details
        *  This function implements calculation of the number of touches on CSD slider,
        *  getting coordinates of each touch and the max number of touches which can be
        *  processed to recognize gestures for the current CSD slider configuration.
        *  Functions returns the slider touch position as the X coordinate. Y coordinate
        *  for CSD sliders is always "0".
        *  This is an internal function. Calling this function from application layer is
        *  not recommended.
        *
        * \param wdgtIndex
        *  Specifies the ID number of the widget, the touch parameters needs to be
        *  returned for.
        *
        * \param touchParams
        *  Pointer to the structure which is intended to store the number of touches,
        *  position of each touch and the max number of touches which can be processed
        *  to recognize gestures for widget, that is passed through the wdgtId nparameter.
        *
        *******************************************************************************/
        __STATIC_INLINE void CapSense_GetCsdSldTouches(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams)
        {
            uint32 tmpVal;
            CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt;
            CapSense_RAM_WD_SLIDER_STRUCT *ptrRamWdgtSld;

            ptrFlashWdgt = &CapSense_dsFlash.wdgtArray[wdgtIndex];
            ptrRamWdgtSld = (CapSense_RAM_WD_SLIDER_STRUCT*)ptrFlashWdgt->ptr2WdgtRam;

            touchParams->touchNumber = 0uL;
            for(tmpVal = 0uL; tmpVal < CapSense_NUM_CENTROIDS; tmpVal++)
            {
                if(ptrRamWdgtSld->position[tmpVal] != CapSense_SLIDER_POS_NONE)
                {
                    touchParams->touchNumber += 1uL;
                }
            }

            touchParams->currentPosition[CapSense_FIRST_FINGER_ID].x = ptrRamWdgtSld->position[CapSense_FIRST_FINGER_ID];
            touchParams->currentPosition[CapSense_FIRST_FINGER_ID].y = 0u;

            #if(CapSense_NUM_CENTROIDS > 1u)
                touchParams->maxTouchNumber = 2u;
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].x = ptrRamWdgtSld->position[CapSense_SECOND_FINGER_ID];
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].y = 0u;
            #else
                touchParams->maxTouchNumber = 1u;
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].x = CapSense_SLIDER_POS_NONE;
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].y = CapSense_SLIDER_POS_NONE;
            #endif /* (2u == CapSense_NUM_CENTROIDS) */
        }
    #endif /* (CapSense_ENABLE == CapSense_SLIDER_WIDGET_EN) */


    #if(CapSense_ENABLE == CapSense_CSD_TOUCHPAD_WIDGET_EN)
        /*******************************************************************************
        * Function Name: CapSense_GetCsdTpTouches
        ****************************************************************************//**
        *
        * \brief
        *  This function is intended to get the number of touches on CSD touchpad, the
        *  position of each touch and the max number of touches which can be processed
        *  to recognize gestures.
        *
        * \details
        *  This function implements calculation of the number of touches on CSD touchpad,
        *  getting coordinates of each touch and the max number of touches which can be
        *  processed to recognize gestures for the current CSD touchpad configuration.
        *  Functions returns the X and Y coordinates of each touch.
        *  This is an internal function. Calling this function from application layer is
        *  not recommended.
        *
        * \param wdgtIndex
        *  Specifies the ID number of the widget, the touch parameters needs to be
        *  returned for.
        *
        * \param touchParams
        *  Pointer to the structure which is intended to store the number of touches,
        *  position of each touch and the max number of touches which can be processed
        *  to recognize gestures for widget, that is passed through the wdgtId nparameter.
        *
        *******************************************************************************/
        __STATIC_INLINE void CapSense_GetCsdTpTouches(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams)
        {
            uint16 tmpPosX;
            uint16 tmpPosY;

            CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt;
            CapSense_RAM_WD_CSD_TOUCHPAD_STRUCT *ptrRamWdgtTp;

            ptrFlashWdgt = &CapSense_dsFlash.wdgtArray[wdgtIndex];
            ptrRamWdgtTp = (CapSense_RAM_WD_CSD_TOUCHPAD_STRUCT*)ptrFlashWdgt->ptr2WdgtRam;

            #if (CapSense_ENABLE == CapSense_CENTROID_5X5_CSD_EN)
                if (0 != (ptrFlashWdgt->staticConfig & CapSense_CENTROID_5X5_MASK))
                {
                    touchParams->maxTouchNumber = 2u;
                    touchParams->touchNumber = ptrRamWdgtTp->position.touchNum;

                    tmpPosX = ptrRamWdgtTp->position.pos[CapSense_FIRST_FINGER_ID].x;
                    touchParams->currentPosition[CapSense_FIRST_FINGER_ID].x = tmpPosX;

                    /* Cypress ID: #233241 */
                    tmpPosY = ptrRamWdgtTp->position.pos[CapSense_FIRST_FINGER_ID].y;
                    tmpPosY = (tmpPosY != CapSense_TOUCHPAD_POS_NONE) ? (ptrFlashWdgt->yResolution - tmpPosY) : tmpPosY;
                    touchParams->currentPosition[CapSense_FIRST_FINGER_ID].y = tmpPosY;

                    tmpPosX = ptrRamWdgtTp->position.pos[CapSense_SECOND_FINGER_ID].x;
                    touchParams->currentPosition[CapSense_SECOND_FINGER_ID].x = tmpPosX;

                    tmpPosY = ptrRamWdgtTp->position.pos[CapSense_SECOND_FINGER_ID].y;
                    tmpPosY = (tmpPosY != CapSense_TOUCHPAD_POS_NONE) ? (ptrFlashWdgt->yResolution - tmpPosY) : tmpPosY;
                    touchParams->currentPosition[CapSense_SECOND_FINGER_ID].y = tmpPosY;
                }
            #endif /* (CapSense_ENABLE == CapSense_CENTROID_5X5_CSD_EN) */

            #if (CapSense_ENABLE == CapSense_CENTROID_3X3_CSD_EN)
                if (0u != (ptrFlashWdgt->staticConfig & CapSense_CENTROID_3X3_MASK))
                {
                    if((CapSense_TOUCHPAD_POS_NONE != ptrRamWdgtTp->posX) && (CapSense_TOUCHPAD_POS_NONE != ptrRamWdgtTp->posY))
                    {
                        touchParams->touchNumber = 1u;
                    }
                    else
                    {
                        touchParams->touchNumber = 0u;
                    }

                    touchParams->maxTouchNumber = 1u;
                    tmpPosX = ptrRamWdgtTp->posX;
                    touchParams->currentPosition[CapSense_FIRST_FINGER_ID].x = tmpPosX;

                    /* Cypress ID: #233241 */
                    tmpPosY = ptrRamWdgtTp->posY;
                    tmpPosY = (tmpPosY != CapSense_TOUCHPAD_POS_NONE) ? (ptrFlashWdgt->yResolution - tmpPosY) : tmpPosY;
                    touchParams->currentPosition[CapSense_FIRST_FINGER_ID].y = tmpPosY;

                    touchParams->currentPosition[CapSense_SECOND_FINGER_ID].x = CapSense_TOUCHPAD_POS_NONE;
                    touchParams->currentPosition[CapSense_SECOND_FINGER_ID].y = CapSense_TOUCHPAD_POS_NONE;
                }
            #endif /* (CapSense_ENABLE == CapSense_CENTROID_3X3_CSD_EN) */
        }
    #endif /* (CapSense_ENABLE == CapSense_CSD_TOUCHPAD_WIDGET_EN) */


    #if(CapSense_ENABLE == CapSense_CSX_TOUCHPAD_WIDGET_EN)
        /*******************************************************************************
        * Function Name: CapSense_GetCsxTpTouches
        ****************************************************************************//**
        *
        * \brief
        *  This function is intended to get the number of touches on CSX touchpad, the
        *  position of each touch and the max number of touches which can be processed
        *  to recognize gestures.
        *
        * \details
        *  This function implements calculation of the number of touches on CSX touchpad,
        *  getting coordinates of each touch and the max number of touches which can be
        *  processed to recognize gestures for the current CSX touchpad configuration.
        *  Functions returns the X and Y coordinates of each touch.
        *  This is an internal function. Calling this function from application layer is
        *  not recommended.
        *
        * \param wdgtIndex
        *  Specifies the ID number of the widget, the touch parameters needs to be
        *  returned for.
        *
        * \param touchParams
        *  Pointer to the structure which is intended to store the number of touches,
        *  position of each touch and the max number of touches which can be processed
        *  to recognize gestures for widget, that is passed through the wdgtId nparameter.
        *
        *******************************************************************************/
        __STATIC_INLINE void CapSense_GetCsxTpTouches(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams)
        {
            uint8 error;
            uint8 index;

            uint16 tmpPosX;
            uint16 tmpPosY;

            static uint8 prevTouchNumber = 0u;
            static uint8 prevTouchId[CapSense_CSX_MAX_FINGERS];

            CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt;
            CapSense_RAM_WD_CSX_TOUCHPAD_STRUCT *ptrRamWdgtTp;

            ptrFlashWdgt = &CapSense_dsFlash.wdgtArray[wdgtIndex];
            ptrRamWdgtTp = (CapSense_RAM_WD_CSX_TOUCHPAD_STRUCT*)ptrFlashWdgt->ptr2WdgtRam;

            touchParams->touchNumber = CapSense_dsRam.snsStatus[wdgtIndex];

            tmpPosX = ptrRamWdgtTp->touch[CapSense_FIRST_FINGER_ID].x;
            touchParams->currentPosition[CapSense_FIRST_FINGER_ID].x = tmpPosX;

            /* Cypress ID: #233241 */
            tmpPosY = ptrRamWdgtTp->touch[CapSense_FIRST_FINGER_ID].y;
            tmpPosY = (tmpPosY != CapSense_TOUCHPAD_POS_NONE) ? (ptrFlashWdgt->yResolution - tmpPosY) : tmpPosY;
            touchParams->currentPosition[CapSense_FIRST_FINGER_ID].y = tmpPosY;

            #if(CapSense_CSX_MAX_FINGERS > 1u)
                touchParams->maxTouchNumber = 2u;
                tmpPosX = ptrRamWdgtTp->touch[CapSense_SECOND_FINGER_ID].x;
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].x = tmpPosX;

                /* Cypress ID: #233241 */
                tmpPosY = ptrRamWdgtTp->touch[CapSense_SECOND_FINGER_ID].y;
                tmpPosY = (tmpPosY != CapSense_TOUCHPAD_POS_NONE) ? (ptrFlashWdgt->yResolution - tmpPosY) : tmpPosY;
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].y = tmpPosY;
            #else
                touchParams->maxTouchNumber = 1u;
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].x = CapSense_TOUCHPAD_POS_NONE;
                touchParams->currentPosition[CapSense_SECOND_FINGER_ID].y = CapSense_TOUCHPAD_POS_NONE;
            #endif /* (CapSense_CSX_MAX_FINGERS > 1u) */

            error = 0u;
            #if (CapSense_CSX_MAX_FINGERS == 1u)
                if((touchParams->touchNumber == 1u) && (prevTouchNumber == 1u))
                {
                    if(prevTouchId[0u] != ptrRamWdgtTp->touch[0u].id)
                    {
                        error++;
                    }
                }
            #else
                if (touchParams->touchNumber == 1u)
                {
                    if (prevTouchNumber == 1u)
                    {
                        if (prevTouchId[0u] != ptrRamWdgtTp->touch[0u].id)
                        {
                            error++;
                        }
                    }
                    else if (prevTouchNumber > 1u)
                    {
                        if ((prevTouchId[0u] != ptrRamWdgtTp->touch[0u].id) &&
                            (prevTouchId[1u] != ptrRamWdgtTp->touch[0u].id))
                        {
                            error++;
                        }
                    }
                }
                else if (touchParams->touchNumber == 2u)
                {
                    if (prevTouchNumber > 0u)
                    {
                        if (prevTouchId[0u] != ptrRamWdgtTp->touch[0u].id)
                        {
                            error++;
                        }
                        else if (prevTouchNumber > 1u)
                        {
                            if (prevTouchId[1u] != ptrRamWdgtTp->touch[1u].id)
                            {
                                error++;
                            }
                        }
                    }
                }
            #endif

            prevTouchNumber = touchParams->touchNumber;
            for (index = 0u; index < CapSense_CSX_MAX_FINGERS; index++)
            {
                prevTouchId[index] = ptrRamWdgtTp->touch[index].id;
            }

            if (error != 0u)
            {
                touchParams->touchNumber = CapSense_CSX_ERROR_TOUCH_NUMBER;
            }
        }
    #endif /* (CapSense_ENABLE == CapSense_CSX_TOUCHPAD_WIDGET_EN) */
#endif /* (CapSense_ENABLE == CapSense_GES_GLOBAL_EN) */


/*******************************************************************************
* Function Name: CapSense_InitializeGestures
****************************************************************************//**
*
* \brief
*  This function is intended to initialize the internal parameters of the
*  Gestures IP.
*
* \details
*  This routine initializes gesture parameters internal to the gesture
*  algorithm. It has to be called once prior to call any API or macro which
*  decodes gestures.
*  This is an internal function. Calling this function from application layer is
*  not recommended.
*
*******************************************************************************/
void CapSense_InitializeGestures(void)
{
    CapSense_dsRam.timestamp = 0uL;

    #if(0u != CapSense_ENABLE == CapSense_GES_GLOBAL_EN)
        CapSense_touchParams.touchNumber = 0u;
        CapSense_touchParams.maxTouchNumber = 0u;
        CapSense_touchParams.touchState = CapSense_TOUCH_VALID;

        CapSense_touchParams.currentPosition[CapSense_FIRST_FINGER_ID].x = CapSense_TMG_INVALID_COORDINATE;
        CapSense_touchParams.currentPosition[CapSense_FIRST_FINGER_ID].y = CapSense_TMG_INVALID_COORDINATE;

        CapSense_touchParams.currentPosition[CapSense_SECOND_FINGER_ID].x = CapSense_TMG_INVALID_COORDINATE;
        CapSense_touchParams.currentPosition[CapSense_SECOND_FINGER_ID].y = CapSense_TMG_INVALID_COORDINATE;

        CapSense_TMG_InitGestures(&CapSense_dsRam.gestures);
    #endif
}


#if (CapSense_ENABLE == CapSense_GES_GLOBAL_EN)
    /*******************************************************************************
    * Function Name: CapSense_DecodeWidgetGestures
    ****************************************************************************//**
    *
    * \brief
    *  Decodes all enabled gestures for the specified widget and returns the
    *  gesture code.
    *
    * \details
    *  This function decodes all the enabled gestures on a specific widget and
    *  returns a code for the detected gesture. Refer to the Gesture tab section
    *  for more details on supported Gestures.
    *
    *  This function is called only after scan and data processing are completed
    *  for the specified widget.
    *
    *  The Timestamp must be updated before calling this function using the
    *  CapSense_IncrementGestureTimestamp() function.
    *
    * \param wdgtIndex
    *  Specifies the ID number of the widget to decode the gesture. A macro for the
    *  widget ID can be found in the CapSense Configuration header file
    *  defined as CapSense_<WidgetName>_WDGT_ID.
    *
    * \return
    *  Returns the status of the gesture detection or the detected gesture code:
    *    - CapSense_NON_VALID_PARAMETER
    *    - CapSense_NO_GESTURE
    *    - CapSense_UNRECOGNIZED_GESTURE
    *    - CapSense_ONE_FINGER_TOUCHDOWN
    *    - CapSense_ONE_FINGER_LIFT_OFF
    *    - CapSense_ONE_FINGER_SINGLE_CLICK
    *    - CapSense_ONE_FINGER_DOUBLE_CLICK
    *    - CapSense_ONE_FINGER_CLICK_AND_DRAG
    *    - CapSense_ONE_FINGER_SCROLL_UP
    *    - CapSense_ONE_FINGER_SCROLL_DOWN
    *    - CapSense_ONE_FINGER_SCROLL_RIGHT
    *    - CapSense_ONE_FINGER_SCROLL_LEFT
    *    - CapSense_ONE_FINGER_SCROLL_INERTIAL_UP
    *    - CapSense_ONE_FINGER_SCROLL_INERTIAL_DOWN
    *    - CapSense_ONE_FINGER_SCROLL_INERTIAL_RIGHT
    *    - CapSense_ONE_FINGER_SCROLL_INERTIAL_LEFT
    *    - CapSense_ONE_FINGER_FLICK_UP
    *    - CapSense_ONE_FINGER_FLICK_DOWN
    *    - CapSense_ONE_FINGER_FLICK_RIGHT
    *    - CapSense_ONE_FINGER_FLICK_LEFT
    *    - CapSense_ONE_FINGER_FLICK_UP_RIGHT
    *    - CapSense_ONE_FINGER_FLICK_DOWN_RIGHT
    *    - CapSense_ONE_FINGER_FLICK_DOWN_LEFT
    *    - CapSense_ONE_FINGER_FLICK_UP_LEFT
    *    - CapSense_ONE_FINGER_EDGE_SWIPE_UP
    *    - CapSense_ONE_FINGER_EDGE_SWIPE_DOWN
    *    - CapSense_ONE_FINGER_EDGE_SWIPE_RIGTH
    *    - CapSense_ONE_FINGER_EDGE_SWIPE_LEFT
    *    - CapSense_ONE_FINGER_ROTATE_CW
    *    - CapSense_ONE_FINGER_ROTATE_CCW
    *    - CapSense_TWO_FINGER_SINGLE_CLICK
    *    - CapSense_TWO_FINGER_SCROLL_UP
    *    - CapSense_TWO_FINGER_SCROLL_DOWN
    *    - CapSense_TWO_FINGER_SCROLL_RIGHT
    *    - CapSense_TWO_FINGER_SCROLL_LEFT
    *    - CapSense_TWO_FINGER_SCROLL_INERTIAL_UP
    *    - CapSense_TWO_FINGER_SCROLL_INERTIAL_DOWN
    *    - CapSense_TWO_FINGER_SCROLL_INERTIAL_RIGHT
    *    - CapSense_TWO_FINGER_SCROLL_INERTIAL_LEFT
    *    - CapSense_TWO_FINGER_ZOOM_IN
    *    - CapSense_TWO_FINGER_ZOOM_OUT
    *
    *******************************************************************************/
    uint32 CapSense_DecodeWidgetGestures(uint32 widgetId)
    {
        uint32 tmpValue;

        #if (0u != CapSense_ONE_FINGER_EDGE_SWIPE_EN)
            static uint32 gestureCounter = 0u;
        #endif

        if(widgetId != CapSense_GESTURE_EN_WIDGET_ID)
        {
            tmpValue = CapSense_NON_VALID_PARAMETER;
        }
        else
        {
            CapSense_GetTouchParams(widgetId, &CapSense_touchParams);

            switch (CapSense_touchParams.touchState)
            {
            case CapSense_TOUCH_UNRECOGNIZED:
                if (CapSense_touchParams.touchNumber == 0u)
                {
                    CapSense_touchParams.touchState = CapSense_TOUCH_VALID;
                    CapSense_TMG_InitGestures(&CapSense_dsRam.gestures);
                    tmpValue = CapSense_NO_GESTURE;
                }
                else
                {
                    tmpValue = CapSense_UNRECOGNIZED_GESTURE;
                }
                break;

            case CapSense_TOUCH_VALID:
                if (CapSense_touchParams.touchNumber > CapSense_touchParams.maxTouchNumber)
                {
                    CapSense_touchParams.touchState = CapSense_TOUCH_UNRECOGNIZED;
                    tmpValue = CapSense_UNRECOGNIZED_GESTURE;
                }
                else
                {
                    tmpValue = CapSense_TMG_DecodeAllGestures((uint32)CapSense_touchParams.touchNumber,
                                                                      CapSense_dsRam.timestamp, CapSense_touchParams.currentPosition);

                    #if (0u != CapSense_ONE_FINGER_EDGE_SWIPE_EN)
                        /* Checks if the gesture is EGDE SWIPE */
                        if (CapSense_ONE_FINGER_EDGE_SWIPE_GROUP == (tmpValue & CapSense_GESTURE_GROUP_MASK))
                        {
                            /* Set flag that the gesture is EGDE SWIPE */
                            gestureCounter = CapSense_ONE_FINGER_EDGE_SWIPE_GESTURE;
                        }
                        else if((gestureCounter == CapSense_ONE_FINGER_EDGE_SWIPE_GESTURE) && (tmpValue == CapSense_ONE_FINGER_TOUCHDOWN))
                        {
                            /* Set flag that the gesture is EGDE SWIPE after the TOUCHDOWN event only */
                            gestureCounter = 0u;
                        }
                        else
                        {
                            /* There was not EDGE SWIPE gestures */
                        }

                        /* Checks if the gesture is INERTIAL_SCROLL and the TOUCHDOWN event has not taken place before */
                        if((tmpValue >= CapSense_ONE_FINGER_SCROLL_INERTIAL_UP) &&
                           (tmpValue <= CapSense_ONE_FINGER_SCROLL_INERTIAL_RIGHT) &&
                           (gestureCounter > 0u))
                        {
                            /* Block INERTIAL_SCROLL detecting */
                            tmpValue = CapSense_NO_GESTURE;
                        }
                    #endif /* (0u != CapSense_ONE_FINGER_EDGE_SWIPE_EN) */
                }
                break;
            default:
                CapSense_touchParams.touchState = CapSense_TOUCH_UNRECOGNIZED;
                tmpValue = CapSense_UNRECOGNIZED_GESTURE;
                break;
            }
        }

        ((CapSense_RAM_WD_BASE_STRUCT *)(CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam))->gestureId = (uint8)tmpValue;

        #if ((CapSense_ENABLE == CapSense_ONE_FINGER_SCROLL_EN) || \
             (CapSense_ENABLE == CapSense_TWO_FINGER_SCROLL_EN))

            if((tmpValue >= CapSense_ONE_FINGER_SCROLL_UP) &&
               (tmpValue <= CapSense_TWO_FINGER_SCROLL_RIGHT))
            {
                ((CapSense_RAM_WD_BASE_STRUCT *)(CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam))->scrollCnt = CapSense_TMG_GetScrollCnt();
            }
            if((tmpValue >= CapSense_ONE_FINGER_SCROLL_INERTIAL_UP) &&
               (tmpValue <= CapSense_TWO_FINGER_SCROLL_INERTIAL_RIGHT))
            {
                ((CapSense_RAM_WD_BASE_STRUCT *)(CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam))->scrollCnt = CapSense_TMG_GetDecayCnt();
            }
        #endif /* ((CapSense_ENABLE == CapSense_ONE_FINGER_SCROLL_EN) || \
                   (CapSense_ENABLE == CapSense_TWO_FINGER_SCROLL_EN)) */

        return (tmpValue);
    }
#endif /* (CapSense_ENABLE == CapSense_GES_GLOBAL_EN) */


#if (CapSense_ENABLE == CapSense_BALLISTIC_MULTIPLIER_EN)
    /*******************************************************************************
    * Function Name: CapSense_InitializeBallisticMultiplier
    ****************************************************************************//**
    *
    * \brief
    *  This function is intended to initialize the internal parameters of the
    *  ballistic multiplier filter.
    *
    * \details
    *  This routine initializes the parameters internal to the ballistic multiplier
    *  algorithm. It has to be called once prior to call the
    *  CapSense_RunBallisticMultiplier() function.
    *  This is an internal function. Calling this function from application layer is
    *  not recommended.
    *
    *******************************************************************************/
    void CapSense_InitializeBallisticMultiplier(void)
    {
        int16 diffPosInit[CapSense_BALLISTIC_DIMENSIONS_NUM] = {0, 0};

        CapSense_bmPrevFingerNum   = 0u;
        CapSense_dsRam.ballisticConfig.touchNumber = 0u;
        CapSense_bmPrevFingerPos.x = CapSense_TOUCHPAD_POS_NONE;
        CapSense_bmPrevFingerPos.y = CapSense_TOUCHPAD_POS_NONE;

        CapSense_TMG_BallisticsMultiplier(&CapSense_dsRam.ballisticConfig, CapSense_dsRam.timestamp, diffPosInit);
    }


    /*******************************************************************************
    * Function Name: CapSense_RunBallisticMultiplier
    ****************************************************************************//**
    *
    * \brief
    *  This function runs the Ballistic multiplier algorithm fo the widget specified
    *  by the wdgtIndex parameter.
    *
    * \details
    *  The CapSense_RunBallisticMultiplier() routine implements the following functionality:
    *   - Gets the type of the widget passed through the wdgtIndex
    *     parameter.
    *   - initializes the CapSense_ballisticMultiplier based on the type of
    *     the widget passed through the wdgtIndex parameter.
    *   - Runs the Ballistic multiplier algorithm for the specified widget.
    *   - Writes a processed position to the posXDelta and posYDelta registers in the
    *     CapSense_RAM_WD_CSD_TOUCHPAD_STRUCT structure.
    *   This is an internal function. Calling this function from application layer is
    *   not recommended.
    *
    * \param wdgtIndex
    *  Specifies the ID number of the widget, the position, processed by Ballistic multiplier
    *  needs to be returned for.
    *
    *******************************************************************************/
    void CapSense_RunBallisticMultiplier(uint32 wdgtIndex)
    {
        CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt;
        CapSense_RAM_WD_CSD_TOUCHPAD_STRUCT *ptrRamWdgtTp;

        uint8 fingerNum = 0u;
        int16 diffPosition[CapSense_BALLISTIC_DIMENSIONS_NUM];
        CapSense_TMG_POSITION_STRUCT curPos = {CapSense_TOUCHPAD_POS_NONE, CapSense_TOUCHPAD_POS_NONE};

        ptrFlashWdgt = &CapSense_dsFlash.wdgtArray[wdgtIndex];
        ptrRamWdgtTp = (CapSense_RAM_WD_CSD_TOUCHPAD_STRUCT*)ptrFlashWdgt->ptr2WdgtRam;

        if(CapSense_BALLISTIC_EN_WIDGET_ID == wdgtIndex)
        {
            /* Get centroid position data for 5x5 CSD touchpad */
            #if (CapSense_ENABLE == CapSense_CENTROID_5X5_CSD_EN)
                if (0u != (ptrFlashWdgt->staticConfig & CapSense_CENTROID_5X5_MASK))
                {
                    curPos.x = ptrRamWdgtTp->position.pos[CapSense_FIRST_FINGER_ID].x;
                    curPos.y = ptrRamWdgtTp->position.pos[CapSense_FIRST_FINGER_ID].y;
                    fingerNum = ((CapSense_TOUCHPAD_POS_NONE != curPos.x) &&
                                 (CapSense_TOUCHPAD_POS_NONE != curPos.y)) ? ptrRamWdgtTp->position.touchNum : 0u;
                }
            #endif

            /* Get centroid position data for 3x3 CSD touchpad */
            #if (CapSense_ENABLE == CapSense_CENTROID_3X3_CSD_EN)
                if (0u != (ptrFlashWdgt->staticConfig & CapSense_CENTROID_3X3_MASK))
                {
                    curPos.x = ptrRamWdgtTp->posX;
                    curPos.y = ptrRamWdgtTp->posY;
                    fingerNum = ((CapSense_TOUCHPAD_POS_NONE != curPos.x) &&
                                 (CapSense_TOUCHPAD_POS_NONE != curPos.y)) ? 1u : 0u;
                }
            #endif

            /* Reset the Ballistic multiplier algorithm to initial state in case if another finger has been recognized
             * as first.
            */
            if((0u != fingerNum) && (CapSense_bmPrevFingerNum > fingerNum))
            {
                CapSense_InitializeBallisticMultiplier();
            }

            if(0u != fingerNum)
            {
                /* Reset the internal variables to the current values if the finger is pressing the first time. */
                if((CapSense_TOUCHPAD_POS_NONE == CapSense_bmPrevFingerPos.x) ||
                   (CapSense_TOUCHPAD_POS_NONE == CapSense_bmPrevFingerPos.y))
                {
                    CapSense_bmPrevFingerNum   = fingerNum;
                    CapSense_bmPrevFingerPos.x = curPos.x;
                    CapSense_bmPrevFingerPos.y = curPos.y;
                }

                /* Calculates the difference between current and previous XY of the first finger. */
                diffPosition[CapSense_X_COORDINATE_INDEX] = (int16)curPos.x - (int16)CapSense_bmPrevFingerPos.x;
                diffPosition[CapSense_Y_COORDINATE_INDEX] = (int16)curPos.y - (int16)CapSense_bmPrevFingerPos.y;
            }
            else
            {
                /* Set the difference between current and previous XY and current number of fingers on the touchpad
                 * to "0" if there are no touches detected.
                */
                fingerNum = 0u;
                diffPosition[CapSense_X_COORDINATE_INDEX] = 0;
                diffPosition[CapSense_Y_COORDINATE_INDEX] = 0;
            }

            /* Initialize the touchNumber field of the ballisticConfig structure with the actual number of fingers
             * on the touchpad surface.
            */
            CapSense_dsRam.ballisticConfig.touchNumber = fingerNum;

            /* Run the Ballistic multiplier algorithm. */
            CapSense_TMG_BallisticsMultiplier(&CapSense_dsRam.ballisticConfig, CapSense_dsRam.timestamp, diffPosition);

            /* Save the processed difference to the target registers. */
            ptrRamWdgtTp->posXDelta = diffPosition[CapSense_X_COORDINATE_INDEX];
            ptrRamWdgtTp->posYDelta = diffPosition[CapSense_Y_COORDINATE_INDEX];

            /* Store the cuttent XY position of the first finger and the number of fingers on the touchpad surface for
             * the next call of the CapSense_RunBallisticMultiplier() function.
            */
            CapSense_bmPrevFingerNum   = fingerNum;
            CapSense_bmPrevFingerPos.x = curPos.x;
            CapSense_bmPrevFingerPos.y = curPos.y;
        }
        else
        {
            /* Set the posXDelta and posYDelta registers to "0" in case of call this function for wrong widget. */
            ptrRamWdgtTp->posXDelta = 0;
            ptrRamWdgtTp->posYDelta = 0;
        }
    }
#endif /* (CapSense_ENABLE == CapSense_BALLISTIC_MULTIPLIER_EN) */


/*******************************************************************************
* Function Name: CapSense_IncrementGestureTimestamp
****************************************************************************//**
*
* \brief
*  Increases the timestamp register for the predefined timestamp interval.
*
* \details
*  This function increments the Component timestamp
*  (CapSense_TIMESTAMP_VALUE register) by the interval specified
*  in the CapSense_TIMESTAMP_INTERVAL_VALUE register. The unit for
*  both registers is millisecond and default value of
*  CapSense_TIMESTAMP_INTERVAL_VALUE is 1.
*
*  It is the application layer responsibility to periodically call this
*  function or register a periodic callback to this function to keep the
*  Component timestamp updated and operational, which is vital for the
*  operation of Gesture and Ballistic multiplier features.
*
*  The Component timestamp can be updated in one of the three methods:
*  - Register a periodic callback for the
*    CapSense_IncrementGestureTimestamp() function.
*  - Periodically call the CapSense_IncrementGestureTimestamp() function
*    by application layer.
*  - Directly modify the timestamp using the
*    CapSense_SetGestureTimestamp() function.
*
*  The interval at which this function is called should match with interval
*  defined in CapSense_TIMESTAMP_INTERVAL_VALUE register. Either the
*  register value can be updated to match the callback interval or the callback
*  can be made at interval set in the register.
*
*  If a timestamp is available from another source or from host controller,
*  application layer may choose to periodically update the Component timestamp
*  by using CapSense_SetGestureTimestamp() function instead of
*  registering a callback.
*
*******************************************************************************/
void CapSense_IncrementGestureTimestamp(void)
{
    CapSense_dsRam.timestamp += CapSense_dsRam.timestampInterval;
}


/*******************************************************************************
* Function Name: CapSense_SetGestureTimestamp
****************************************************************************//**
*
* \brief
*  Rewrites the timestamp register by the specified value.
*
* \details
*  This function writes the specified value into the Component timestamp
*  (i.e. CapSense_TIMESTAMP_VALUE register).
*
*  If a timestamp is available from another source or from host controller,
*  application layer may choose to periodically update the Component timestamp
*  by using this function instead of registering a callback.
*
*  It is not recommended to modify the Component timestamp arbitrarily or
*  simultaneously use with the CapSense_IncrementGestureTimestamp()
*  function.
*
* \param timestampValue
*  Specifies the timestamp value (in ms).
*
*******************************************************************************/
void CapSense_SetGestureTimestamp(uint32 timestampValue)
{
    CapSense_dsRam.timestamp = timestampValue;
}


/* [] END OF FILE */
