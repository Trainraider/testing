# SPDX-License-Identifier: GPL-2.0-only

project('testing', 'c', 
  license: 'GPL-2.0-only')

include = include_directories('.')

types_dep = dependency('types', fallback : ['types', 'types_dep'])
testing_dep = declare_dependency(include_directories: include)

install_headers('test.h', subdir: 'trainslibs')

pkg_mod = import('pkgconfig')
pkg_mod.generate(name: 'libtesting',
  filebase: 'testing',
  subdirs: 'trainslibs',
  url: 'https://github.com/Trainraider/testing.git',
  description: 'Minimal/incomplete testing framework')
