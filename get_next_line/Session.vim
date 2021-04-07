let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/1337/get_next_line
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +37 get_next_line.c
badd +2 main.c
badd +71 get_next_line_utils.c
badd +10 get_next_line.h
badd +1 ~/Desktop/libft
badd +15 ~/Desktop/libft/ft_calloc.c
badd +1 ~/Desktop/1337/get_next_line
badd +10 ~/Desktop/libft/ft_strlcat.c
badd +15 ~/Desktop/libft/ft_strdup.c
badd +1 ~/Desktop/libft/,
badd +15 ~/Desktop/libft/ft_strchr.c
badd +4 man://strcat(3)
badd +13 ~/Desktop/DayZZ/day05/mel-haih4/ex16/ft_strcat.c
badd +1 man://strlen(3)
badd +193 text
argglobal
%argdel
$argadd get_next_line.c
set stal=2
edit get_next_line_utils.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
5,14fold
5,14fold
19,31fold
36,48fold
53,66fold
71,84fold
5
normal! zo
let s:l = 36 - ((35 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
36
normal! 0
tabedit main.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 12 - ((9 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
12
normal! 014|
tabnext 2
set stal=1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToOF
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
