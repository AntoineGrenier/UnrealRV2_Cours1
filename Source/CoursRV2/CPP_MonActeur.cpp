// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MonActeur.h"

// Sets default values
ACPP_MonActeur::ACPP_MonActeur()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Initialisation de TArray
    Messages.Add(TEXT("Bienvenue"));
    Messages.Add(TEXT("En cours de chargement"));

    // Initialisation de TMap
    Statistics.Add(TEXT("Kills"), 0);
    Statistics.Add(TEXT("Deaths"), 0);

    // Initialisation de TSet
    Tags.Add(TEXT("UniqueTag1"));
    Tags.Add(TEXT("UniqueTag2"));
    Tags.Add(TEXT("UniqueTag2"));

    // Initialisation de l'état
    Status = EActorStatus::Idle;

    // Initialisation des attributs
    Attributes = FActorAttributes();
}

// Called when the game starts or when spawned
void ACPP_MonActeur::BeginPlay()
{
	Super::BeginPlay();
	

    // Affichage des éléments de TArray
    for (const FString& Message : Messages)
    {
        UE_LOG(LogTemp, Log, TEXT("Message: %s"), *Message);
    }

    // Affichage des éléments de TMap
    for (const TPair<FString, int32>& Stat : Statistics)
    {
        UE_LOG(LogTemp, Log, TEXT("Stat: %s - %d"), *Stat.Key, Stat.Value);
    }

    // Affichage des éléments de TSet
    for (const FString& Tag : Tags)
    {
        UE_LOG(LogTemp, Log, TEXT("Tag: %s"), *Tag);
    }
}

// Called every frame
void ACPP_MonActeur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Met à jour les attributs
void ACPP_MonActeur::UpdateAttributes(int32 NewHealth, int32 NewStrength)
{
    Attributes.Health = NewHealth;
    Attributes.Strength = NewStrength;

    UE_LOG(LogTemp, Log, TEXT("Attributs mis à jour : Santé = %d, Force = %d"), Attributes.Health, Attributes.Strength);
}

// Change l'état de l'acteur
void ACPP_MonActeur::ChangeStatus(EActorStatus NewStatus)
{
    Status = NewStatus;
    UE_LOG(LogTemp, Log, TEXT("Statut modifié : %s"), *UEnum::GetValueAsString(Status));
}