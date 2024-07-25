project('Rhyme', 'cpp',
        default_options : [
                'cpp_std=c++20',
                'werror=true',
                'warning_level=2',
                'b_pie=false',
                'b_staticpic=false',
                'debug=false',
                'cpp_eh=none',
                'cpp_rtti=false'
        ]
)

cpp_args = ['-ffreestanding', '-nostdlib', '-D__KERNEL__', '-Wthread-safety']
src = []
inc = []
args = []
deps = []

if get_option('buildtype').startswith('debug')
        args += '-DDEBUG=1'
endif

subdir('src')

deps += dependency('chdrs', fallback: ['chdrs', 'chdrs_dep'])
deps += dependency('cxxhdrs', fallback: ['cxxhdrs', 'cxxhdrs_dep'])
deps += dependency('flanterm', fallback: ['flanterm', 'flanterm_dep'])

arch_path = join_paths(meson.current_source_dir(), 'src/arch', target_machine.cpu_family())

ld_file = files(arch_path + '/link.ld')[0]

git = find_program('git', disabler: true, required: false)

if git.found()
        r = run_command('git', 'rev-parse', '--short', 'HEAD', check: false)

        git_rev = ''

        if r.returncode() == 0
                git_rev = r.stdout().strip()
        else
                git_rev = 'unknown'
        endif

        cpp_args += ['-D__RHMY_GIT_VERSION__="@0@"'.format(git_rev)]
endif

executable(
        'rhm',
        sources: src,
        include_directories: inc,
        cpp_args: cpp_args,
        dependencies: deps,
        link_args: '-Wl,-T@0@'.format(ld_file),
)