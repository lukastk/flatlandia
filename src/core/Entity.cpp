/**
 * @Author Lukas Kikuchi (lukas.kikuchi@gmail.com)
 * @date 29 August 2016
 * @brief  Source file for Entity.
 */

#include "core/Entity.h"

/* Protected */

Entity::Entity(EntityUpdateProtocol default_update_protocol) {
  update_protocol = default_update_protocol;
}

/* Public */

EntityUpdateProtocol Entity::get_update_protocol() {
  return update_protocol;
}
void Entity::set_update_protocol(EntityUpdateProtocol update_protocol) {
  this->update_protocol = update_protocol;
}
