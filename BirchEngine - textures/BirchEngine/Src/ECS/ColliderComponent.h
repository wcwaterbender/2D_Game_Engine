#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"


class ColliderComponent : public Component
{

public:

	SDL_Rect collider;
	std::string tag;


	TransformComponent* transform;

	ColliderComponent(std::string t)
	{
		tag = t;
	}

	void init() override
	{
		//make sure we dont add duplicate Transform component
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->hasComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		Game::colliders.push_back(this);
	}

	void update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};