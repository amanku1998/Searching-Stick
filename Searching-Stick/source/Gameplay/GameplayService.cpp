#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"
#include "Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
		collection_controller = new StickCollectionController();
	}

	GameplayService::~GameplayService()
	{
		delete (gameplay_controller);
		delete(collection_controller);
	}

	void GameplayService::initializeRandomSeed() // Helper function for initializing the random seed
	{
		// Seed the random number generator with the current time
		// This ensures that the sequence of random numbers will be different each time the program is run
		// The `std::time(nullptr)` function returns the current time as the number of seconds since the Unix epoch (January 1, 1970)
		// The `static_cast<unsigned int>` is used to cast the `std::time_t` value to an `unsigned int`, which is required by `std::srand`
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
		collection_controller->initialize();
		initializeRandomSeed();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
		collection_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
		collection_controller->render();
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
		collection_controller->reset();
	}

	void GameplayService::searchElement(Collection::SearchType search_type)
	{
		collection_controller->searchElement(search_type);
	}

	Collection::SearchType GameplayService::getCurrentSearchType()
	{
		return collection_controller->getSearchType();
	}

	int GameplayService::getNumberOfSticks()
	{
		return collection_controller->getNumberOfSticks();
	}

}