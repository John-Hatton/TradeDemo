#include "TradeDemo/Classes/MyPlayer/MyPlayer.h"

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Net/UnrealNetwork.h"


// Forward Declarations
class USpringArmComponent;
class UCameraComponent;
class USoundCue;
class UAnimMontage;

AMyPlayer::AMyPlayer()
{
	// Set this pawn to call Tick() every frame.  
	PrimaryActorTick.bCanEverTick = true;

	// Assuming you are in the constructor of your character class (AMyCharacter::AMyCharacter())
	auto MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	MeshComp->SetupAttachment(RootComponent);  // Assuming RootComponent is valid

	// Then you can load a skeletal mesh asset and assign it to this component
	// static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/PathToYourAsset.YourAssetName"));
	// if(MeshAsset.Succeeded())
	// {
	// 	MeshComp->SetSkeletalMesh(MeshAsset.Object);
	// }
	
	// Set the default values for the health
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;

	// Set the default values for player stats
	Speed = 600.0f;
	Money = 1000.0f;
	
	// Create the inventory for the player
	Inventory = CreateDefaultSubobject<UInventory>(TEXT("Inventory"));

	// Create a camera boom (pulls towards the player if there's a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	RootComponent = CameraBoom;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Create default values for Camera variables
	BaseTurnRate = 45.0f;
	BaseLookUpRate = 45.0f;
	HipTurnRate = 90.0f;
	HipLookUpRate = 80.0f;
	AimingTurnRate = 20.0f;
	AimingLookUpRate = 15.0f;
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind the input axis
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyPlayer::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyPlayer::LookUp);
	// bind the jump action to the Jump function of the Character class
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayer::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyPlayer::StopJumping);
	// bind the crouch action to the Crouch function of the Character class
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyPlayer::Crouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMyPlayer::UnCrouch);

}

void AMyPlayer::MoveForward(float Value)
{
	// Move the player forwards or backwards
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// Find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
        
		// Add movement in that direction
		FVector NewLocation = GetActorLocation() + Direction * Value;
		SetActorLocation(NewLocation);
	}
}

void AMyPlayer::MoveRight(float Value)
{
	// Move the player right or left
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// Find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		// Add movement in that direction
		FVector NewLocation = GetActorLocation() + Direction * Value;
		SetActorLocation(NewLocation);
	}
}

void AMyPlayer::TurnAtRate(float Rate)
{
	// Calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyPlayer::LookUpAtRate(float Rate)
{
	// Calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMyPlayer::Turn(float Value)
{
	float TurnScaleFactor;
	TurnScaleFactor = MouseHipTurnRate;
	AddControllerYawInput(Value * TurnScaleFactor);
}

void AMyPlayer::LookUp(float Value)
{
	float LookUpScaleFactor;
	LookUpScaleFactor = MouseHipLookUpRate;
	AddControllerPitchInput(Value * LookUpScaleFactor);
}

float AMyPlayer::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damageApplied = CurrentHealth - DamageAmount;
	SetCurrentHealth(damageApplied);
	return damageApplied;
}

void AMyPlayer::Jump()
{
	// TODO: Implement Jump function
}

void AMyPlayer::StopJumping()
{
    // TODO: Implement StopJumping function
}

void AMyPlayer::Crouch()
{
	// TODO: Implement Crouch function
}

void AMyPlayer::UnCrouch()
{
	// TODO: Implement UnCrouch function
}

void AMyPlayer::Interact()
{
	// Code for interaction goes here. This could involve interacting with NPCs, objects, etc.
	UE_LOG(LogTemp, Warning, TEXT("Interact function called."));
}

void AMyPlayer::SetCurrentHealth(float HealthValue)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		CurrentHealth = FMath::Clamp(HealthValue, 0.0f, MaxHealth);
		OnRep_CurrentHealth();
	}
}

void AMyPlayer::OnRep_CurrentHealth()
{
	// This function will be called on clients to update their UI or other elements after health changes
}

void AMyPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyPlayer, CurrentHealth);
}
