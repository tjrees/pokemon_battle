// move_library.cpp
#include "move_library.h"

// ThunderShock
ThunderShock::ThunderShock()
: Attack("ThunderShock", Electric, 30, 30, 100, Special, false, 40, 0) {}

ThunderShock::~ThunderShock() {}
void ThunderShock::use() {}

// Growl
Growl::Growl()
: Status("Growl", Normal, 40, 40, 100, 0) {}

Growl::~Growl() {}
void Growl::use() {}

// TailWhip
TailWhip::TailWhip()
: Status("Tail Whip", Normal, 30, 30, 100, 0) {}

TailWhip::~TailWhip() {}
void TailWhip::use() {}

// QuickAttack
QuickAttack::QuickAttack()
: Attack("Quick Attack", Normal, 30, 30, 100, Physical, true, 40, 1) {}

QuickAttack::~QuickAttack() {}
void QuickAttack::use() {}

// Scratch
Scratch::Scratch()
: Attack("Scratch", Normal, 35, 35, 100, Physical, true, 40, 0) {}

Scratch::~Scratch() {}
void Scratch::use() {}

// Ember
Ember::Ember()
: Attack("Ember", Fire, 25, 25, 100, Special, false, 40, 0) {}

Ember::~Ember() {}
void Ember::use() {}

// MetalClaw
MetalClaw::MetalClaw()
: Attack("Metal Claw", Steel, 35, 35, 95, Physical, true, 50, 0) {}

MetalClaw::~MetalClaw() {}
void MetalClaw::use() {}
