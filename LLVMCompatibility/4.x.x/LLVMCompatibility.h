#pragma once

#include <llvm/ExecutionEngine/Orc/CompileUtils.h>
#include <llvm/ExecutionEngine/Orc/ExecutionUtils.h>
#include <llvm/ExecutionEngine/RuntimeDyld.h>

namespace llvm_compat {
using namespace llvm;

typedef JITSymbolResolver SymbolResolver;
typedef JITSymbol JITSymbolInfo;
typedef JITSymbol JITSymbol;
typedef orc::LocalCXXRuntimeOverrides CXXRuntimeOverrides;

uint64_t JITSymbolAddress(JITSymbol &symbol);

JITSymbolFlags
JITSymbolFlagsFromObjectSymbol(const object::BasicSymbolRef &symbol);

object::OwningBinary<object::ObjectFile>
compileModule(orc::SimpleCompiler &compiler, llvm::Module &module);

std::unique_ptr<Module> parseBitcode(MemoryBufferRef bufferRef,
                                     LLVMContext &context);

} // namespace llvm_compat
