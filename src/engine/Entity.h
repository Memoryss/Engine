//
//  Author: Shervin Aflatooni
//

#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <map>

#include "Transform.h"
#include "Shader.h"
#include "Input.h"

class Engine;

class EntityComponent;

class Entity
{
public:
  Entity(const std::string& tag);
  Entity(void);
  ~Entity(void);

  void addChild(Entity* child);
  void addComponent(EntityComponent* component);

  void updateInputAll(Input *input, int delta);
  void updateAll(int delta);
  void renderAll(Shader *shader);
  void registerWithEngineAll(Engine *engine);

  Transform& getTransform(void);

  std::vector<Entity*> *getChildren(void);

  glm::mat4& getWorldMatrix(void);

  glm::vec4 getPosition(void);
  glm::vec4 getDirection(void);

  static std::vector<Entity*> findByTag(const std::string& tag);

private:
  Transform transform;

  Entity *parentEntity;

  std::vector<Entity*> children;
  std::vector<EntityComponent*> components;

  glm::mat4 worldMatrix;

  std::string m_tag;

  static void setTag(Entity *entity, const std::string& tag);

  static std::map<std::string, std::vector<Entity*>> taggedEntities;
};

#endif
