#pragma once
///@file

#include <optional>

#ifndef _WIN32
# include <sys/resource.h>
#endif

#include "file-path.hh"

namespace nix {

/**
 * If cgroups are active, attempt to calculate the number of CPUs available.
 * If cgroups are unavailable or if cpu.max is set to "max", return 0.
 */
unsigned int getMaxCPU();

/**
 * Change the stack size.
 */
void setStackSize(size_t stackSize);

/**
 * Restore the original inherited Unix process context (such as signal
 * masks, stack size).

 * See unix::startSignalHandlerThread(), unix::saveSignalMask().
 */
void restoreProcessContext(bool restoreMounts = true);

/**
 * @return the path of the current executable.
 */
std::optional<Path> getSelfExe();

}
