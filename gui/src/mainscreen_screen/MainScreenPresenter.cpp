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
