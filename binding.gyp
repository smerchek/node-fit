{
  "targets": [
    {
      "target_name": "binding",
      "sources": [ 
         "src/binding.cc",
         "src/listener.cc",
         "src/fitparser.cc",
         "libfit/fit.cpp",
         "libfit/fit_accumulated_field.cpp",
         "libfit/fit_accumulator.cpp",
         "libfit/fit_buffered_record_mesg_broadcaster.cpp",
         "libfit/fit_crc.cpp",
         "libfit/fit_decode.cpp",
         "libfit/fit_field.cpp",
         "libfit/fit_field_definition.cpp",
         "libfit/fit_mesg.cpp",
         "libfit/fit_mesg_broadcaster.cpp",
         "libfit/fit_mesg_definition.cpp",
         "libfit/fit_mesg_with_event_broadcaster.cpp",
         "libfit/fit_profile.cpp",
         "libfit/fit_unicode.cpp",
      ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'conditions': [
        ['OS=="mac"', {
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
          }
        }]
      ]
    }
  ]
}