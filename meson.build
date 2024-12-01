project(
  'aoc2024',
  'c',
  version: '0.1',
  default_options: ['warning_level=3', 'c_std=c17'],
)
unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

src = []
unity_test = []
subdir('day1')
inc = include_directories('day1')
test = executable(
  'app_test',
  sources: [src, unity_test],
  include_directories: inc,
  dependencies: unity_dependency,
)

test('app_test', test)
