 /**
  * \class Entity
  *
  * \ingroup flatlandia
  *
  * \brief Entities represent objects that are located in a World.
  *
  * Entities represent objects that are located within the World. Both items
  * like food or creatures are entities.
  *
  * Update protocol:
  * The update protcol of the entity tells the World the desired frequency of
  * updating the Entity needs.
  *
  * \note Attempts at zen rarely work.
  *
  * \author (last to touch it) $Author: Lukas Kikuchi (lukas.kikuchi@gmail.com)$
  *
  * \date $Date: 2016/08/29 $
  *
  * Contact: bv@bnl.gov
  *
  * Created on: 2016/08/29
  *
  */

#ifndef ENTITY_H
#define ENTITY_H

/*! 
enum EntityUpdateProtocol {
  NeverUpdate,
  Update,
  UpdateOnEvent
}

class Entity {

private:


  EntityUpdateProtocol update_protocol; /// The desired update protocol of the Entity.

protected:

  /*! Protected constructor for Entity.
    * \param default_update_protocol sets the default update protocol of the entity.
    *
    * The constructor is protected as is meant to be used to define certain core
    * properties of the entity by calling it from child-classes.
    */
  Entity(EntityUpdateProtocol default_update_protocol);

public:

  /// Returns the value of the desired EntityUpdateProtocol of the entity.
  EntityUpdateProtocol get_update_protocol();

  /// Sets the desired EntityUpdateProtocol of the entity, and updates its status in the World.
  void set_update_protocol(EntityUpdateProtocol update_protocol);
}

#endif
