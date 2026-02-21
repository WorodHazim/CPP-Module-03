C++ Module 03 – Inheritance
42 Abu Dhabi – C++98 Standard

## Overview
This module introduces Inheritance in C++, including:

1. Basic class construction
2. Constructor & Destructor chaining
3. Derived classes
4. Multiple inheritance
5. Diamond problem
6. Attribute shadowing
7. Method resolution
All exercises follow C++98 standard and Orthodox Canonical Form.

## Conceptual Roadmap
Before diving into exercises, here’s the conceptual evolution:
<img width="770" height="428" alt="Screenshot 2026-02-21 at 4 08 30 PM" src="https://github.com/user-attachments/assets/3d06d628-7c6d-43f1-9a1d-2011ab076fed" />

We start with a simple base class → then extend it → then combine both derived classes into a diamond structure.

## EX00 – ClapTrap
Goal:
Create a base class that models a simple combat robot.

<pre> 
class ClapTrap {
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
};
</pre>

Attributes meaning

| Attribute     | Meaning       |
| ------------- |:-------------:|
| name	       | robot name     |
| hitPoints    | health         |
| energyPoints | action resource|
| attackDamage | damage dealt   |

Behavior Functions
<pre> 
void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
</pre>

Logic Flow (attack)
<pre> 
IF hitPoints <= 0 → do nothing
IF energyPoints <= 0 → do nothing
ELSE:
    energyPoints--
    print attack message
</pre>

Object Lifecycle
<pre>
Constructor → initializes values
Destructor → prints destruction message
</pre>

## EX01 – ScavTrap
Goal:
Create a derived class from ClapTrap.
<pre>
class ScavTrap : public ClapTrap
</pre>
What Happens During Creation?
<pre>
Create ScavTrap
    ↓
ClapTrap constructor runs FIRST
    ↓
ScavTrap constructor runs
</pre>
Why?
Because base class must exist before derived class can extend it.

New Stats:
| Attribute     | Value         |
| ------------- |:-------------:|
| HP	        | 100   |
| Energy     | 50         |
| Damage  | 20 |

New Ability
<pre>
  void guardGate();
</pre>
Prints gatekeeper mode message.

** Key Concept Learned **

1. Inheritance reuses logic but modifies identity.
2. ScavTrap: Uses ClapTrap attributes
3. ScavTrap: Overrides attack()
4. ScavTrap: Adds new behavior

## EX02 – FragTrap
Very similar to ScavTrap.
<pre>
  class FragTrap : public ClapTrap
</pre>

Stats
| Attribute     | Value         |
| ------------- |:-------------:|
| HP	        | 100   |
| Energy     | 100         |
| Damage  | 30 |

Special Ability
<pre>
  void highFivesGuys();
</pre>

What’s important here?
1. Constructor chaining still applies.
2. Different stats = different specialization.

We now have TWO classes derived from ClapTrap.

Structure now:

<pre>
        ClapTrap
        /      \
   ScavTrap   FragTrap
</pre>

   
## EX03 – DiamondTrap (The tricky part)

Now things get serious.
<pre>
  class DiamondTrap : public ScavTrap, public FragTrap
</pre>
Diamond Structure
<pre>
            ClapTrap
           /        \
      ScavTrap    FragTrap
           \        /
           DiamondTrap
</pre>

The Problem:
Both ScavTrap and FragTrap inherit from ClapTrap.

That means DiamondTrap contains:
1.ClapTrap (via ScavTrap)
2.ClapTrap (via FragTrap)

TWO ClapTrap subobjects.
This causes ambiguity and duplication.

** The Trick

The subject says:
"ClapTrap instance of DiamondTrap will be created once, and only once."

This implies using virtual inheritance.
✅ Correct Approach
<pre>
class ScavTrap : virtual public ClapTrap {};
class FragTrap : virtual public ClapTrap {};
</pre>

Now DiamondTrap has only ONE ClapTrap inside it.

Attribute Shadowing
DiamondTrap must have:
<pre>
  private:
    std::string name;
</pre>

BUT ClapTrap also has:
<pre>
  std::string name;
</pre>

So DiamondTrap now contains:
<pre>
  DiamondTrap::name
  ClapTrap::name
</pre>

Constructor Logic

If DiamondTrap name is:
<pre>
  "Bob"
</pre>

Then:
<pre>
  DiamondTrap::name = "Bob"
ClapTrap::name = "Bob_clap_name"
</pre>

whoAmI()
<pre>
  void DiamondTrap::whoAmI()
{
    std::cout << "Diamond name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

</pre>

Note the explicit scope:
<pre>
  ClapTrap::name
</pre>


This resolves ambiguity.

Construction Order in EX03
<pre>
ClapTrap constructor
ScavTrap constructor
FragTrap constructor
DiamondTrap constructor
</pre>
Destruction is reverse.

## What This Module Teaches Deeply

1. IS-A relationship
2. Code reuse
3. Constructor chaining
4. Ambiguity resolution
5. Multiple inheritance dangers
6. Attribute shadowing
8. Scope resolution operator
9. Virtual inheritance

