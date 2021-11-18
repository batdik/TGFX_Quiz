#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{
}

void MainScreenPresenter::deactivate()
{

}

const Config::MainConfig_t& MainScreenPresenter::getConfig() const {
	return model->getMainConfig();
}

const int& MainScreenPresenter::getAngle() const {
	return model->getAngleValue();
}

const int& MainScreenPresenter::getUpdateInterval() const {
	return model->getSpeedUpdateInterval();
}