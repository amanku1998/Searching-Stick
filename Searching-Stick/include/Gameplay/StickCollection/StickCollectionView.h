#pragma once


namespace Gameplay
{
	namespace Collection
	{
		class StickCollectionView
		{
		public :
			StickCollectionView();
			~StickCollectionView();

			void initialize();
			void update();
			void render();
		};
	}
}