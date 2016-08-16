# Introduction
We will specify the general organization of the whole simulation in this file


---
# Specification of the simulation
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

## World
1. locations of food sources
2. locations of animals
3. day-night-cycle
4. (shelter)



---
# Technical realization

---