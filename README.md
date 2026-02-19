# sys-calls

## Build

gcc -Wall -Wextra -o sig_ignore src/sig_ignore.c
gcc -Wall -Wextra -o sig_quit_prompt src/sig_quit_prompt.c
gcc -Wall -Wextra -o write_seek src/write_seek.c
gcc -Wall -Wextra -o dup2_warmup src/dup2_warmup.c
gcc -Wall -Wextra -o redirect_exec src/redirect_exec.c

## Run

./sig_ignore
./sig_quit_prompt
./write_seek && cat output_seek.txt
./dup2_warmup && cat dup2_out.txt
./redirect_exec lsout.txt && cat lsout.txt
