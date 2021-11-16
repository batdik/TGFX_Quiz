#include <gui/configscreen_screen/ConfigScreenView.hpp>
#include <gui/configscreen_screen/ConfigScreenPresenter.hpp>

ConfigScreenPresenter::ConfigScreenPresenter(ConfigScreenView& v)
    : view(v)
{

}

void ConfigScreenPresenter::activate()
{

}

void ConfigScreenPresenter::deactivate()
{

}

const Config::ConfigConfig_t& ConfigScreenPresenter::getConfig() const {
	return model->getConfigConfig();
}

const int& ConfigScreenPresenter::getAngle() const{
	return model->getAngleValue();
}

void ConfigScreenPresenter::setAngle(int angle) {
	model->setAngleValue(angle);
}