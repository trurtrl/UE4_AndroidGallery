#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AndroidGateway.generated.h"
//#include "EngineMinimal.h"
//#include "Core.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExternalStoragePath, const FString, Path);

UCLASS()
class ANDROGALLERY_API UAndroidGateway : public UObject
{
	GENERATED_BODY()

public:

    UAndroidGateway();
 
    void AskGalleryRootPath();

	FOnExternalStoragePath OnExternalStoragePath;
   
	UFUNCTION()
	void OnPermissionGrantedHandle(const TArray<FString>& Permissions, const TArray<bool>& GrantResults);

private:

	FString m_StoragePermission;

	bool CheckPermissionToReadStorage();
	void AskPermissionToReadStorage();
	FString AskPath();

};
