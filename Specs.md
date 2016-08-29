# Introduction
We will specify the general organization of the whole simulation in this file.

---

# Specification of the simulation

Performance and modularity are the main concerns with regards to the implementation
of the simulation. The core philosophy is that we want to maximize modularity
without sacrificing performance (in other words, performance is prioritized over
modularity). The architecture of the simulation reflects this. The core
components of the simulation are relatively simple and interaction in between
them will be done using the interfaces of abstract classes. Following is a list
of the main abstract classes of the simulation (indented bullets indicate subclasses):

 - FlatlandiaSim
 - World
 - Entity
    - Agent
      - Creature
 - AgentAI
 - Genome
 - AIGenome

The following sections will go into detail on the specification of the various
classes.

## FlatlandiaSim

Responsible for the running of the simulation. Information about the simulation
and the manipulation of the simulation should be done through the public methods of
_FlatlandiaSim_.

###### Features

 - Initialize simulation.
 - Run simulation.
 - I/O (Save simulation state)
 - Export snapshots containing necessary information for the visualization of the
simulation.

## World

Handles the physical nature of the world in which the simulation entities inhabit
(the physical laws of which in most cases will be extremely simple). It keeps track
of and manages the position and state of all the entities of the world.

The properties of the world are recorded as state data, accessible to the entities
of the simulation. Examples of information that can be restored in these are,
for example, time of day (to implement day-and-night cycles), day in the year
(to simulate seasons) or air moisture.

###### Features

 - Physics engine
 - Manages the entities
 - World properties (StateData)

## Entity

Entities represent objects that are located within the World. Both items like food
or creatures are entities.

Entities can decide whether it wants to be registered on the update cycle of the
simulation (that is, whether it wants to run some logic every cycle of the simulation).

## Agent

An entity that calls an _AgentAI_ object during its update cycle.

## Creature

A subclass of _Agent_. In addition to its agency, the creature can give birth.
The procedure with which a creature mates and gives birth is dependent on the
implementation. The genes of the physical aspects of the creature is represented
in a _Genome_ object, and the genes of the AI is represented in an _AIGenome_
object.

## AgentAI

Controls an Agent object.

## Genome

Holds the genetic code for the physical attributes of a creature. The object can
mutate and be mated with other Genomes.

The class is abstract and is meant to be extended, but there is an aspect that is meant to be
held the same in all the subclasses of it. The way in which the Genome object
stores the physical attributes can not be overridden. The reason for this is that
any Creature object should be able to read the information within the Genome,
regardless of what subclass of the Genome class it is.

The modular part of the Genome class is the mutation and mating behavior.

## AIGenome

Holds the genetic code for the attributes of an AgentAI. The object can mutate and
be mated with other AIGenome objects.

Since the informational structure of an AI (especially neural networks) can be quite
complex, there has to be a separate AIGenome subclass associated with each AgentAI
subclass (it cannot be kept general as in the case of the Genome class). In fact,
in the mating procedure between creatures, it is through the
AIGenome that we get the AgentAI instantiation to go inside the child creature.

# Ideas

## Animal
Animals have a set of status information and of ways to interact with other animals as well as with the environment.

### Status
Statuselements with brackets may not be realized at first. Some of the
1. Energy
2. "Happiness/fear"
3. moving speed
4. strength
5. (group Status)
6. location
7. direction

### Genome
The genome encodes the important factors of all animals, as for example
1. Behaviour
2. maximum levels of strength, happiness, energy, moving speed etc.
2. senses (hearing, seeing, smelling, taste)
3. cyrcadian rythm
4. sex?
5. (skills - skills describe the level with which an animal can interact with the world or other animals)

It changes by random mutation as well as by random mixing of the parents genome. Genes might be dominant or recessive.
Different genes might influence each other.
Genes might be turned off and on by different actions of the creature.

### Behaviour
Every part of the animals behaviour is classified as one of two classes. Either it's an interaction with another animal or with the world itself (We could add things like interaction with itself to see if they to recreational stuff (or masturbation). It  also might be needed to build stuff like individual motion of limbs later down the road).

#### Interaction with the World
In the beginning the interaction of the animal with the world is limited in the beginning.
1. Move forward/backward
2. Rotate
3. Eat
4. Sleep
5. Look around
6. any other interaction like building tools and stuff later down the road

#### Interaction with other animals
1. Mate
2. (Share Food)
3. (eat)
4. (communicate (active and passive))

---

# Technical realization

## World

### World states

The _state_ of the world can be displayed using a public _StateData_ array. For example,
the world can contain state information on the moisture, time and day of the year.
At any point during the running of the simulation, the _StateData_ array would look
similar to this:

| Index | StateData ID | Value |
|-------|--------------|-------|
| 0     | MOISTURE     | 0.2   |
| 1     | TIME         | 11    |
| 2     | DAY_IN_YEAR  | 231   |

When entities are added to a simulation, they can request to receive the index of
a state data in the array, by looking it up using the _StateData ID_. This index
can then be used for the duration of the simulation to access the state data.

## Entity

### Update Cycle

In the protected constructor of the Entity class, a boolean value should be passed
that decides whether it should register itself onto the update cycle of the simulation.

Potentially, we could also have entities that only updated when interacted with.

The frequency of updating that an Entity requires is displayed in public by the Entity
by its value of its EntityUpdateProtocol. The world should learn of any changes in the
update protocol of an Entity through calling of event functions.

---
