
#include <iostream>
#include <obs-module.h>
#if __has_include(<obs-frontend-api.h>)
#include <obs-frontend-api.h>
#else
#include <obs-frontend-api/obs-frontend-api.h>
#endif
#include <obs-data.h>
#include <string>
#include <map>
#include <iostream>
#include <utility>
#include "obs-action.h"
#include "forms/obs-actions-widget.hpp"
#include "obs-controller.hpp"
#include <QtWidgets/QAction>
#include <QtWidgets/QMainWindow>
#include <QIcon>
using namespace std;



OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("obs-midi", "en-US")


void register_gui(char *path)
{
	QWidget *cont = new OBSActionsWidget();
	QIcon *ic = new QIcon(path);
	QString *na = new QString("OBS");
	obs_frontend_add_output_control(na, cont);
	bfree(path);
}

bool obs_module_load(void)
{
	char *path = obs_module_file("midi.svg");
	blog(LOG_INFO, "OBS Actions Module Loaded!");
	register_gui(path);
	Controller *controller = new Controller();
	return true;
}
void obs_module_unload()
{
	blog(LOG_INFO, "goodbye!");
}


