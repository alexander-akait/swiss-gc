/* lang.c - UI localization tables for Swiss.

   Russian (UTF-8) translations keyed on the English source string. Rendered by
   the Cyrillic-capable font path in gui/IPLFontWrite.c. */
#include <string.h>
#include "lang.h"
#include "swiss.h"

char *uiLanguageStr[] = {"English", "Русский"};

typedef struct {
	char *en;
	char *ru;
} Translation;

// Russian text is stored as raw UTF-8 string literals.
static const Translation translations[] = {
	// Settings page titles
	{"Global Settings (1/6):",     "Общие настройки (1/6):"},
	{"Interface Settings (2/6):",  "Настройки интерфейса (2/6):"},
	{"Network Settings (3/6):",    "Настройки сети (3/6):"},

	// Navigation buttons
	{"Back",           "Назад"},
	{"Next",           "Далее"},
	{"Save & Exit",    "Сохранить и выйти"},
	{"Discard & Exit", "Отменить и выйти"},
	{"Reset to defaults", "Сбросить настройки"},

	// Global settings page labels
	{"System Boot Mode:",        "Режим загрузки системы:"},
	{"System Sound:",            "Звук системы:"},
	{"System Video:",            "Видео системы:"},
	{"Screen Position:",         "Положение экрана:"},
	{"System Language:",         "Язык системы:"},
	{"Configuration Device:",    "Устройство конфигурации:"},
	{"Swiss Video Mode:",        "Видеорежим Swiss:"},
	{"Init DVD Drive at startup:", "Инициализация DVD при запуске:"},
	{"Stop DVD Drive motor:",    "Останавливать мотор DVD:"},
	{"Configure Audio Buffer:",  "Настройка аудиобуфера:"},
	{"SD/IDE-EXI Speed:",        "Скорость SD/IDE-EXI:"},
	{"AVE Compatibility:",       "Совместимость AVE:"},
	{"Force DTV Status:",        "Принудительный статус DTV:"},
	{"RetroTINK-4K HDMI Input:", "Вход HDMI RetroTINK-4K:"},
	{"Disable Controller Recalibration:", "Откл. рекалибровку контроллера:"},
	{"Disable Controller Rumble:", "Откл. вибрацию контроллера:"},
	{"Enable USB Gecko:",        "Включить USB Gecko:"},
	{"Wait for USB Gecko:",      "Ждать USB Gecko:"},
	{"Simulated MRAM Size:",     "Размер эмулируемой MRAM:"},
	{"CPU Temperature Calibration:", "Калибровка температуры ЦП:"},

	// Interface settings page labels
	{"UI Language:",                 "Язык интерфейса:"},
	{"File Browser Type:",           "Тип файлового браузера:"},
	{"File Browser Type for apps:",  "Тип браузера для программ:"},
	{"File Browser Type for games:", "Тип браузера для игр:"},
	{"File Management:",             "Управление файлами:"},
	{"Recent List:",                "Список недавних:"},
	{"Show hidden files:",          "Показывать скрытые файлы:"},
	{"Hide unknown file types:",    "Скрывать неизвестные типы:"},
	{"Boot without prompts:",       "Загрузка без подтверждений:"},
	{"Flatten directory:",          "Свернуть каталог:"},

	// Common values
	{"Yes",        "Да"},
	{"No",         "Нет"},
	{"On",         "Вкл."},
	{"Off",        "Выкл."},
	{"Auto",       "Авто"},
	{"None",       "Нет"},
	{"Default",    "По умолч."},
	{"Production", "Рабочий"},
	{"Stereo",     "Стерео"},
	{"Mono",       "Моно"},
	{"Lazy",       "Ленивый"},
	{"Standard",   "Стандартный"},
	{"Fullwidth",  "Широкий"},
	{"Carousel",   "Карусель"},
	{"Slot A",     "Слот A"},
	{"Slot B",     "Слот B"},
};
#define NUM_TRANSLATIONS (sizeof(translations) / sizeof(translations[0]))

char *_(const char *en)
{
	if(en == NULL || swissSettings.uiLanguage == UILANG_ENGLISH) {
		return (char *)en;
	}
	for(unsigned int i = 0; i < NUM_TRANSLATIONS; i++) {
		// Fast path for the common case where the same literal is passed in.
		if(translations[i].en == en || strcmp(translations[i].en, en) == 0) {
			return translations[i].ru;
		}
	}
	return (char *)en;
}
