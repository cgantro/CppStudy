# Enable ASan + UBSan. Call from studies/72-sanitizers or ad-hoc debugging.
# Usage: target_sanitizers(<target>)
function(target_sanitizers target)
  if(MSVC)
    message(WARNING "ASan/UBSan not available on MSVC — skipping ${target}")
    return()
  endif()
  target_compile_options(${target} PRIVATE
    -fsanitize=address,undefined
    -fno-omit-frame-pointer
  )
  target_link_options(${target} PRIVATE -fsanitize=address,undefined)
endfunction()
