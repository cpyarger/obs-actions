#pragma once
#include <obs.hpp>
#include <memory>
#include <QObject>
void setup_ui();
void reloadEvents();
#define OBS_ACTIONS_VERSION "0.1"

#define blog(level, msg, ...) blog(level, "[obs-actions] " msg, ##__VA_ARGS__)
