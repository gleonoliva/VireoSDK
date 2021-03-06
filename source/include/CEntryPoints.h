/**

Copyright (c) 2014-2015 National Instruments Corp.

This software is subject to the terms described in the LICENSE.TXT file

SDG
*/

/*! \file
    \brief  C entry points for core Vireo functions. Used when the runtime is built and loaded as a library
 */

namespace Vireo {

//------------------------------------------------------------
// Keep in sync with eggShellResultEnum in module_eggShell.js
typedef enum {
    kEggShellResult_Success = 0,
    kEggShellResult_ObjectNotFoundAtPath = 1,
    kEggShellResult_UnexpectedObjectType = 2,
    kEggShellResult_InvalidResultPointer = 3,
    kEggShellResult_UnableToCreateReturnBuffer = 4,
} EggShellResult;
//------------------------------------------------------------
//! TypeManager functions
VIREO_EXPORT Int32 Vireo_Version();
VIREO_EXPORT Int32 Vireo_MaxExecWakeUpTime();
VIREO_EXPORT void* EggShell_Create(TypeManagerRef tm);
VIREO_EXPORT NIError EggShell_REPL(TypeManagerRef tm, const Utf8Char* commands, Int32 length);
VIREO_EXPORT Int32 EggShell_ExecuteSlices(TypeManagerRef tm, Int32 numSlices, Int32 millisecondsToRun);
VIREO_EXPORT TypeRef EggShell_GetTypeList(TypeManagerRef tm);
VIREO_EXPORT void EggShell_Delete(TypeManagerRef tm);
VIREO_EXPORT Int32 EggShell_PeekMemory(TypeManagerRef tm, const char* viName, const char* eltName,
                                       Int32 bufferSize, char* buffer);
VIREO_EXPORT Int32 EggShell_PokeMemory(TypeManagerRef tm, const char* viName, const char* eltName,
                                       Int32 bufferSize, char* buffer);
VIREO_EXPORT void EggShell_WriteDouble(TypeManagerRef tm, const char* viName, const char* eltName, Double d);
VIREO_EXPORT Double EggShell_ReadDouble(TypeManagerRef tm, const char* viName, const char* eltName);
VIREO_EXPORT void EggShell_WriteValueString(TypeManagerRef tm, const char* viName, const char* eltName,
                                            const char* format, const char* value);
VIREO_EXPORT const char* EggShell_ReadValueString(TypeManagerRef tm, const char* viName, const char* eltName,
                                                  const char* format);
VIREO_EXPORT EggShellResult EggShell_GetArrayMetadata(TypeManagerRef tm, const char* viName, const char* eltName,
    char** arrayTypeName, Int32* arrayRank, unsigned char** arrayBegin);
VIREO_EXPORT Int32 EggShell_GetArrayDimLength(TypeManagerRef tm, const char* viName, const char* eltName, Int32 dim);
VIREO_EXPORT Int32 EggShell_ResizeArray(TypeManagerRef tm, const char* viName, const char* eltName,
                                        Int32 rank, Int32* newLengths);
VIREO_EXPORT void* Data_GetStringBegin(StringRef stringObject);
VIREO_EXPORT Int32 Data_GetStringLength(StringRef stringObject);
VIREO_EXPORT void Data_WriteString(TypeManagerRef tm, StringRef stringObject, const unsigned char* buffer,
                                   Int32 length);
VIREO_EXPORT Int32 Data_ReadBoolean(Boolean* booleanPointer);
VIREO_EXPORT void Data_WriteBoolean(Boolean* destination, Int32 value);
VIREO_EXPORT void Data_WriteInt32(Int32* destination, Int32 value);
VIREO_EXPORT void Data_WriteUInt32(UInt32* destination, UInt32 value);
//------------------------------------------------------------
//! Typeref functions
VIREO_EXPORT TypeRef TypeManager_Define(TypeManagerRef typeManager, const char* typeName, const char* typeString);
VIREO_EXPORT TypeRef TypeManager_FindType(TypeManagerRef typeManager, const char* typeName);
VIREO_EXPORT Int32 TypeRef_TopAQSize(TypeRef typeRef);
VIREO_EXPORT Boolean TypeRef_IsFlat(TypeRef typeRef);
VIREO_EXPORT Boolean TypeRef_IsValid(TypeRef typeRef);
VIREO_EXPORT Boolean TypeRef_HasCustomDefault(TypeRef typeRef);
VIREO_EXPORT EncodingEnum TypeRef_BitEncoding(TypeRef typeRef);
VIREO_EXPORT Int32 TypeRef_Alignment(TypeRef typeRef);
VIREO_EXPORT void TypeRef_Name(TypeRef typeRef, Int32* bufferSize, char* buffer);
VIREO_EXPORT Int32 TypeRef_ElementOffset(TypeRef typeRef);
VIREO_EXPORT Int32 TypeRef_Rank(TypeRef typeRef);
VIREO_EXPORT PointerTypeEnum TypeRef_PointerType(TypeRef typeRef);
VIREO_EXPORT TypeRef TypeRef_Next(TypeRef typeRef);
VIREO_EXPORT UsageTypeEnum TypeRef_ElementUsageType(TypeRef typeRef);
VIREO_EXPORT Int32 TypeRef_SubElementCount(TypeRef typeRef);
VIREO_EXPORT TypeRef TypeRef_GetSubElementByIndex(TypeRef typeRef, Int32 index);
//------------------------------------------------------------
//! TypedBlock functions
VIREO_EXPORT Int32 Data_RawBlockSize(TypedBlock* object);
VIREO_EXPORT Int32 Data_Length(TypedBlock* object);
VIREO_EXPORT TypeRef Data_Type(TypedBlock* object);
VIREO_EXPORT Int32 Data_GetLength(TypedBlock* object, Int32 dimension);
VIREO_EXPORT void Data_Resize1D(TypedBlock* object, Int32 size);
VIREO_EXPORT void Data_ResizeDimensions(TypedBlock* object, Int32 rank, Int32* sizes);
VIREO_EXPORT void* Data_RawPointerFromOffset(TypedBlock* object, Int32 offset);
VIREO_EXPORT void Data_Read1Byte(TypedBlock* object, Int32 offset, Int8* value);
VIREO_EXPORT void Data_Write1Byte(TypedBlock* object, Int32 offset, Int8 value);
VIREO_EXPORT void Data_Read2Bytes(TypedBlock* object, Int32 offset, Int16* value);
VIREO_EXPORT void Data_Write2Bytes(TypedBlock* object, Int32 offset, Int16 value);
VIREO_EXPORT void Data_Read4Bytes(TypedBlock* object, Int32 offset, Int32* value);
VIREO_EXPORT void Data_Write4Bytes(TypedBlock* object, Int32 offset, Int32 value);
VIREO_EXPORT void Data_Read8Bytes(TypedBlock* object, Int32 offset, Int64* value);
VIREO_EXPORT void Data_Write8Bytes(TypedBlock* object, Int32 offset, Int64 value);
VIREO_EXPORT void Data_ReadPointer(TypedBlock* object, Int32 offset, void** value);
VIREO_EXPORT void Data_WritePointer(TypedBlock* object, Int32 offset, void* value);
VIREO_EXPORT void Data_ReadBytes(TypedBlock* object, Int32 offset, Int32 count, Int32* buffer);
VIREO_EXPORT void Data_WriteBytes(TypedBlock* object, Int32 offset, Int32 count, Int32* buffer);
//------------------------------------------------------------
//! Occurrence functions
VIREO_EXPORT void Occurrence_Set(OccurrenceRef occurrence);

}  // namespace Vireo
