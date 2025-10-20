#pragma once

UENUM(BlueprintType)
enum class EDamageType : uint8
{
	None,
	Melee,
	Projectile,
	Explosion,
	Environmental
};

UENUM(BlueprintType)
enum class EDamageResponse : uint8
{
	None,
	HitReact,
	Stagger,
	Stun,
	Knockback
};
/*

*/
