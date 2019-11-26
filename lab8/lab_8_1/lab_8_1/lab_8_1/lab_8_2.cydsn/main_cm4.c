#include "project.h"
#include "GUI.h"
#include "pervasive_eink_hardware_driver.h"
#include "cy_eink_library.h"
#include "LCDConf.h"
/* Кеш буфера зображення */
uint8 imageBufferCache[CY_EINK_FRAME_SIZE] = {0};
/* Посилання на растрове зображення для екрану при запуску програми */
extern GUI_CONST_STORAGE GUI_BITMAP bmCypressLogoFullColor_PNG_1bpp;
/* Function prototypes */
void ShowFontSizesNormal(void);
void ShowFontSizesBold(void);
void ShowTextModes(void);
void ShowTextWrapAndOrientation(void);
void Show2DGraphics1(void);
void Show2DGraphics2(void);
/* Масив функцій демонстраційних сторінок */
void (*demoPageArray[])(void) = {
 ShowFontSizesNormal,
 ShowFontSizesBold,
 ShowTextModes,
 ShowTextWrapAndOrientation,
 Show2DGraphics1,
 Show2DGraphics2
};
/* Число демонстраційних сторінок */
#define NUMBER_OF_DEMO_PAGES (sizeof(demoPageArray)/sizeof(demoPageArray[0]))
/* Ця функція оновлює дисплей з даними буферу дисплею.
* Функція спочатку передає вміст буферу дисплею EmWin
* до основного буферу дисплея EInk. Потім викликає
* функцію Cy_EINK_ShowFrame для оновлення дисплея, а потім
* вона копіює буфер дисплея EmWin в буфер кешу дисплея Eink */
/*Побічні ефекти:
* Для оновлення дисплею потрібно близько секунди. Це функція блокує
* і повертається лише після оновлення дисплею.
* Side Effects:
* It takes about a second to refresh the display. This is a blocking function
* and only returns after the display refresh
*
*******************************************************************************/
void UpdateDisplay(cy_eink_update_t updateMethod, bool powerCycle)
{
 cy_eink_frame_t* pEmwinBuffer;
 /* Отримання вказівника на буфер дисплею Emwin */
 pEmwinBuffer = (cy_eink_frame_t*)LCD_GetDisplayBuffer();
 /* Оновлення EInk дисплею */
 Cy_EINK_ShowFrame(imageBufferCache, pEmwinBuffer, updateMethod, powerCycle);
 /* Копіювання EmWin буферу дисплею в буфер кешу дисплея */
 memcpy(imageBufferCache, pEmwinBuffer, CY_EINK_FRAME_SIZE);
}
/* Ця функція відображає екран при запуску програми з Cypress Logo
* та текст опису демоверсії */
void ShowStartupScreen(void)
{
 /* Задання кольору переднього плану та розміру шрифту */
 GUI_SetFont(GUI_FONT_16B_1);
 GUI_SetColor(GUI_BLACK);
 GUI_SetBkColor(GUI_WHITE);
 GUI_Clear();
 GUI_DrawBitmap(&bmCypressLogoFullColor_PNG_1bpp, 2, 2);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("CYPRESS", 132, 85);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("EMWIN GRAPHICS", 132, 105);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("EINK DISPLAY DEMO", 132, 125);
 /* Пересилка на екран даних буферу дисплея */
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* Ця функція показує екран із інструкцією для натискання кнопки SW2
* та для прокручування різних сторінок дисплею */
void ShowInstructionsScreen(void)
{
 /* Set font size, background color and text mode */
 GUI_SetFont(GUI_FONT_16B_1);
 GUI_SetBkColor(GUI_WHITE);
 GUI_SetColor(GUI_BLACK);
 GUI_SetTextMode(GUI_TM_NORMAL);
 /* Очистка дисплея */
 GUI_Clear();
 /* Відображення тексту інструкцій */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("PRESS SW2 ON THE KIT", 132, 58);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("TO SCROLL THROUGH ", 132, 78);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("DEMO PAGES!", 132, 98);
 /* Передача на екран даних буферу дисплея */
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* Ця функція відображує на дисплеї різні розміри шрифту */
void ShowFontSizesNormal(void)
{
 /* Задання розміру шрифту, кольору тла (фону) та режиму тексту */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetBkColor(GUI_WHITE);
 GUI_SetColor(GUI_BLACK);
 GUI_SetTextMode(GUI_TM_NORMAL);
 /* Очистка дисплея */
 GUI_Clear();
 /* Відображення назви сторінки */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("1 OF 6: NORMAL FONTS", 132, 5);
 /* Font8_1*/
 GUI_SetFont(GUI_FONT_8_1);
 GUI_DispStringAt("GUI_Font8_1", 10, 30);
 /* Font10_1*/
 GUI_SetFont(GUI_FONT_10_1);
 GUI_DispStringAt("GUI_Font10_1", 10, 40);
 /* Font13_1*/
 GUI_SetFont(GUI_FONT_13_1);
 GUI_DispStringAt("GUI_Font13_1", 10, 52);
 /* Font16_1*/
 GUI_SetFont(GUI_FONT_16_1);
 GUI_DispStringAt("GUI_Font16_1", 10, 67);
 /* Font20_1*/
 GUI_SetFont(GUI_FONT_20_1);
 GUI_DispStringAt("GUI_Font20_1", 10, 85);
 /* Font24_1*/
 GUI_SetFont(GUI_FONT_24_1);
 GUI_DispStringAt("GUI_Font24_1", 10, 107);
 /* Font32_1*/
 GUI_SetFont(GUI_FONT_32_1);
 GUI_DispStringAt("GUI_Font32_1", 10, 133);
 /* Send the display buffer data to display*/
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* Ця функція відображує різні розміри шрифту */
void ShowFontSizesBold(void)
{
 /* Задання розміру шрифту, кольору тла (фону) та режиму тексту */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetBkColor(GUI_WHITE);
 GUI_SetColor(GUI_BLACK);
 GUI_SetTextMode(GUI_TM_NORMAL);
 /* Очищення дисплею */
 GUI_Clear();
 /* Відображення назви сторінки */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("2 OF 6: BOLD FONTS", 132, 5);
 /* Font13B_1*/
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_DispStringAt("GUI_Font13B_1", 5, 25);
 /* Font13HB_1*/
 GUI_SetFont(GUI_FONT_13HB_1);
 GUI_DispStringAt("GUI_Font13HB_1", 5, 40);
 /* Font16B_1*/
 GUI_SetFont(GUI_FONT_16B_1);
 GUI_DispStringAt("GUI_Font16B_1", 5, 55);
 /* FontComic18B_1*/
 GUI_SetFont(GUI_FONT_COMIC18B_1);
 GUI_DispStringAt("GUI_FontComic18B_1", 5, 73);
 /* Font20B_1*/
 GUI_SetFont(GUI_FONT_20B_1);
 GUI_DispStringAt("GUI_Font20B_1", 5, 93);
 /* Font24B_1*/
 GUI_SetFont(GUI_FONT_24B_1);
 GUI_DispStringAt("GUI_Font24B_1", 5, 115);
 /* Font32B_1*/
 GUI_SetFont(GUI_FONT_32B_1);
 GUI_DispStringAt("GUI_Font32B_1", 5, 141);
 /* Пересилка даних буферу дисплею на дисплей */
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* Ця функція відображає наступне:
* 1. Текст вирівнюється зліва, по центру та справа
* 2. Підкреслити, накреслити та прокреслити текст стилю
* 3. Нормальний, зворотний, прозорий та текстовий режими XOR *
void ShowTextModes(void)
{
 /* Задання розміру шрифту, кольору тла (фону) та режиму тексту */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetColor(GUI_BLACK);
 GUI_SetBkColor(GUI_WHITE);
 GUI_SetTextMode(GUI_TM_NORMAL);
 GUI_SetTextStyle(GUI_TS_NORMAL);
 /* Очищення дисплею */
 GUI_Clear();
 /* Відображення назви сторінки */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("3 OF 6: TEXT ALIGNMENTS, STYLES AND MODES", 132, 5);
 /* Відображення тексту, вирівняного зліва */
 GUI_SetTextAlign(GUI_TA_LEFT);
 GUI_DispStringAt("TEXT ALIGNMENT LEFT", 0, 30);
 /* Відображення тексту, вирівняного по центру */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("TEXT ALIGNMENT CENTER", 132, 45);
 /* Відображення тексту, вирівняного зправа */
 GUI_SetTextAlign(GUI_TA_RIGHT);
 GUI_DispStringAt("TEXT ALIGNMENT RIGHT", 263, 60);
 /* Відображення підкресленого тексту */
 GUI_SetTextStyle(GUI_TS_UNDERLINE);
 GUI_SetTextAlign(GUI_TA_LEFT);
 GUI_DispStringAt("TEXT STYLE UNDERLINE", 0, 75);
 /* Відображення накресленого тексту */
 GUI_SetTextStyle(GUI_TS_OVERLINE);
 GUI_SetTextAlign(GUI_TA_LEFT);
 GUI_DispStringAt("TEXT STYLE OVERLINE", 0, 90);
 /* Відображення закресленого тексту */
 GUI_SetTextStyle(GUI_TS_STRIKETHRU);
 GUI_SetTextAlign(GUI_TA_LEFT);
 GUI_DispStringAt("TEXT STYLE STRIKETHROUGH", 0, 105);
 /* Створення прямокутника, замальованого чорним кольором */
 GUI_SetColor(GUI_BLACK);
 GUI_FillRect(0, 120, 263, 175);
 /* Відображення двох діагональних ліній */
 GUI_SetColor(GUI_WHITE);
 GUI_SetPenSize(3);
 GUI_DrawLine(0, 120, 263, 175);
 GUI_DrawLine(0, 175, 263, 120);
 /* Встановлення кольору тексту білим на чорному фоні */
 GUI_SetColor(GUI_BLACK);
 GUI_SetBkColor(GUI_WHITE);
 /* Встановлення стилю тексту нормальним */
 GUI_SetTextStyle(GUI_TS_NORMAL);
 /* Display text in normal mode. This will print black text in
 a white box */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_SetTextMode(GUI_TM_NORMAL);
 GUI_DispStringAt("TEXT MODE NORMAL", 132, 135);
 /* Відображення тексту у інверсному режимі. Тоді відобразиться чорний текст
 на білому фоні */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_SetTextMode(GUI_TM_REV);
 GUI_DispStringAt("TEXT MODE REVERSE", 132, 150);
 /* Пересилка на екран даних з буферу дисплею */
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* void ShowTextWrapAndOrientation(void) Ця функція викликає функції орієнтації
 тексту та обгортання тексту */
void ShowTextWrapAndOrientation(void)
{
 GUI_RECT leftRect = {4, 19, 24, 166};
 GUI_RECT rightRect = {238, 19, 258, 166};
 GUI_RECT middleRect = {29, 19, 233, 166};
 GUI_RECT middleRectMargins = {31, 20, 232, 165};
 const char leftText[] = "ROTATED TEXT CCW";
 const char rightText[] = "ROTATED TEXT CW";
 const char middleText[] = "This project demonstrates displaying 2D graphics
in an EInk display using Segger EmWin Graphics Library. \n\nThis page shows the
text wrap and text rotation features. In the left rectangle, the text is rotated
counter clockwise and in the right rectangle, the text is rotated clockwise.";
 /* Встановлення розміру шрифту, переднього плану та кольору тла */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetColor(GUI_BLACK);
 GUI_SetBkColor(GUI_WHITE);
 GUI_SetTextMode(GUI_TM_NORMAL);
 GUI_SetTextStyle(GUI_TS_NORMAL);
 /* Очищення дисплею */
 GUI_Clear();
 /* Display page title */
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("4 OF 6: TEXT WRAP AND ROTATION", 132, 5);
 /* Draw rectangles to hold text */
 GUI_DrawRectEx(&leftRect);
 GUI_DrawRectEx(&rightRect);
 GUI_DrawRectEx(&middleRect);
 /* Display string in left rectangle rotated counter clockwise */
 GUI_DispStringInRectEx(leftText, &leftRect, GUI_TA_HCENTER | GUI_TA_VCENTER,
strlen(leftText), GUI_ROTATE_CCW);
 /* Display string in right rectangle rotated clockwise */
 GUI_DispStringInRectEx(rightText, &rightRect, GUI_TA_HCENTER |
GUI_TA_VCENTER, strlen(rightText), GUI_ROTATE_CW);
 /* Display string in middle rectangle with word wrap */
 GUI_DispStringInRectWrap(middleText, &middleRectMargins, GUI_TA_LEFT,
GUI_WRAPMODE_WORD);
 /* Send the display buffer data to display*/
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* void Show2DGraphics1(void)
* Ця функція відображає наступну двовимірну графіку:
* 1. Горизонтальні лінії різної товщини.
* 2. Вертикальні лінії різної товщини.
* 3. Дуги.
* 4.
* Summary: This function displays the following 2D graphics
* 1. Horizontal lines with various pen widths
* 2. Vertical lines with various pen widths
* 3. Arcs
* 4. Замальований прямокутник. */
void Show2DGraphics1(void)
{
 /* Set font size, foreground and background colors */
 GUI_SetColor(GUI_BLACK);
 GUI_SetBkColor(GUI_WHITE);
 GUI_SetTextMode(GUI_TM_NORMAL);
 GUI_SetTextStyle(GUI_TS_NORMAL);
 /* Clear the screen */
 GUI_Clear();
 /* Display page title */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("5 OF 6: 2D GRAPHICS - 1", 136, 5);
 /* Display labels */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("H-LINES", 68, 85);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("V-LINES", 204, 85);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("ARCS", 68, 163);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("ROUNDED RECT", 204, 163);
 /* Horizontal lines */
 GUI_SetPenSize(1);
 GUI_DrawLine(10, 25, 125, 25);
 GUI_SetPenSize(2);
 GUI_DrawLine(10, 35, 125, 35);
 GUI_SetPenSize(3);
 GUI_DrawLine(10, 45, 125, 45);
 GUI_SetPenSize(4);
 GUI_DrawLine(10, 55, 125, 55);
 GUI_SetPenSize(5);
 GUI_DrawLine(10, 65, 125, 65);
 GUI_SetPenSize(6);
 GUI_DrawLine(10, 75, 125, 75);
 /* Vertical lines */
 GUI_SetPenSize(1);
 GUI_DrawLine(168, 20, 168, 80);
 GUI_SetPenSize(2);
 GUI_DrawLine(180, 20, 180, 80);
 GUI_SetPenSize(3);
 GUI_DrawLine(192, 20, 192, 80);
 GUI_SetPenSize(4);
 GUI_DrawLine(204, 20, 204, 80);
 GUI_SetPenSize(5);
 GUI_DrawLine(216, 20, 216, 80);
 GUI_SetPenSize(6);
 GUI_DrawLine(228, 20, 228, 80);
 GUI_SetPenSize(7);
 GUI_DrawLine(240, 20, 240, 80);
 /* Дуги */
 GUI_SetPenSize(2);
 GUI_DrawArc(68, 160, 10, 10, 0, 180);
 GUI_DrawArc(68, 160, 20, 20, 0, 180);
 GUI_DrawArc(68, 160, 30, 30, 0, 180);
 GUI_DrawArc(68, 160, 40, 40, 0, 180);
 GUI_DrawArc(68, 160, 50, 50, 0, 180);
 /* Rounded rectangle */
 GUI_FillRoundedRect(146, 108, 262, 160, 5);
 /* Send the display buffer data to display*/
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* void Show2DGraphics2(void)
* Ця функція відображає наступну двовимірну графіку:
* 1. Концентричні кола.
* 2. Концентричні еліпси. */
void Show2DGraphics2(void)
{
 /* Set font size, foreground and background colors */
 GUI_SetColor(GUI_BLACK);
 GUI_SetBkColor(GUI_WHITE);
 GUI_SetTextMode(GUI_TM_NORMAL);
 GUI_SetTextStyle(GUI_TS_NORMAL);
 /* Clear the screen */
 GUI_Clear();
 /* Display page title */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("6 OF 6: 2D GRAPHICS - 2", 132, 5);
 /* Display labels */
 GUI_SetFont(GUI_FONT_13B_1);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("CIRCLE", 68, 85);
 GUI_SetTextAlign(GUI_TA_HCENTER);
 GUI_DispStringAt("ELLIPSE", 204, 85);
 /* Concentric Circles */
 GUI_DrawCircle(68, 51, 30);
 GUI_DrawCircle(68, 51, 25);
 GUI_DrawCircle(68, 51, 20);
 GUI_DrawCircle(68, 51, 15);
 GUI_DrawCircle(68, 51, 10);
 /* Concentric Ellipses */
 GUI_DrawEllipse(204, 51, 50, 30);
 GUI_DrawEllipse(204, 51, 40, 25);
 GUI_DrawEllipse(204, 51, 30, 20);
 GUI_DrawEllipse(204, 51, 20, 15);
 /* Send the display buffer data to display*/
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* void ClearScreen(void)
* Ця функція очищає екран дисплею. */
void ClearScreen(void)
{
 GUI_SetColor(GUI_BLACK);
 GUI_SetBkColor(GUI_WHITE);
 GUI_Clear();
 UpdateDisplay(CY_EINK_FULL_4STAGE, true);
}
/* void WaitforSwitchPressAndRelease(void)
* Ця функція реалізує вивід інформації "Wait for button press and release"
* Спочатку чекає натискання кнопки, а потім чекає відпускання кнопки.
* Побічні ефекти:
* Ця функція блокування та працює тільки при натисканні, відпусканні кнопки */
void WaitforSwitchPressAndRelease(void)
{
 /* Wait for SW2 to be pressed */
 while(Status_SW2_Read() != 0);

 /* Wait for SW2 to be released */
 while(Status_SW2_Read() == 0);
}
/* int main(void)
* Це головна функція. В ній виконуються наступні функції:
* 1. Ініціалізація EmWin бібліотеки.
* 2. Відображення екрану при запуску програми протягом 3 сек.
* 3. Відображення на екрані інструкцій та очікування на натискання
* та відпускання кнопки.
* 4. Прокручування усередині циклу 6 демонстраційних сторінок під час
* кожного натискання та відпускання кнопки. */
int main(void)
{

 uint8 pageNumber = 0;

 __enable_irq(); /* Дозвіл глобальних переривань. */

 /* Iніціалізація emWin графіки */
 GUI_Init();
 /* Запуск інтерфейсу e-Ink та включення його живлення */
 Cy_EINK_Start(20);
 Cy_EINK_Power(1);
 /* Відображення екрану при запуску програми */
 ShowStartupScreen();
 CyDelay(2000);
 /* Відображення інструкції на екрані дисплею */
 ShowInstructionsScreen();
 WaitforSwitchPressAndRelease();

 for(;;)
 {
 /* Включення зеленого світлодіода перед оновленням сторінки */
 Cy_GPIO_Write(GreenLED_PORT, GreenLED_NUM, 0);

 /* Використовуючи pageNumber як індекс, оновіть дисплей за допомогою
 демонстраційного екрана. Далі приведено функції, які викликаються
 послідовно одна за одною.
 ShowFontSizesNormal()
 ShowFontSizesBold()
 ShowTextModes()
 ShowTextWrapAndOrientation()
 Show2DGraphics1()
 Show2DGraphics2()
 */
 (*demoPageArray[pageNumber])();

 /* Вимкнення зеленого світлодіода LED після оновлення сторінки */
 Cy_GPIO_Write(GreenLED_PORT, GreenLED_NUM, 1);

 /* Очікування події: натискання кнопки */
 WaitforSwitchPressAndRelease();

 /* Перебір номерів сторінок */
 pageNumber = (pageNumber+1) % NUMBER_OF_DEMO_PAGES;
 }
}