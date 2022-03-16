{ pkgs }: {
	deps = [
		pkgs.clang_12
        pkgs.gcc
		pkgs.cmake
		pkgs.gdb
        pkgs.sqlite3
	];
}