
void get_mime_type(char *file_name, char *result){
    /*
        Get MIME Type of File from file extension
        @file_name : File Name with File Extension
        @result : [ Return Value ]
    */
    char *name_array;
    char extension[16];

    name_array = strtok(file_name, ".");
    while(name_array != NULL){
        if(strlen(name_array) < 16){
            strcpy(extension, name_array);
        }
        name_array = strtok(NULL, ".");
    }

    //result = malloc(128);
    strcpy(result, "text/plain");

    if(strcmp(extension, "3dm") == 0){strcpy(result, "x-world/x-3dmf"); return;}
    if(strcmp(extension, "3dmf") == 0){strcpy(result, "x-world/x-3dmf"); return;}

    switch(extension[0]){
    case 'a':
        goto check_ext_a;
        break;
    case 'b':
        goto check_ext_b;
        break;
    case 'c':
        goto check_ext_c;
        break;
    case 'd':
        goto check_ext_d;
        break;
    case 'e':
        goto check_ext_e;
        break;
    case 'f':
        goto check_ext_f;
        break;
    case 'g':
        goto check_ext_g;
        break;
    case 'h':
        goto check_ext_h;
        break;
    case 'i':
        goto check_ext_i;
        break;
    case 'j':
        goto check_ext_j;
        break;
    case 'k':
        goto check_ext_k;
        break;
    case 'l':
        goto check_ext_l;
        break;
    case 'm':
        goto check_ext_m;
        break;
    case 'n':
        goto check_ext_n;
        break;
    case 'o':
        goto check_ext_o;
        break;
    case 'p':
        goto check_ext_p;
        break;
    case 'q':
        goto check_ext_q;
        break;
    case 'r':
        goto check_ext_r;
        break;
    case 's':
        goto check_ext_s;
        break;
    case 't':
        goto check_ext_t;
        break;
    case 'u':
        goto check_ext_u;
        break;
    case 'v':
        goto check_ext_v;
        break;
    case 'w':
        goto check_ext_w;
        break;
    case 'x':
        goto check_ext_x;
        break;
    case 'z':
        goto check_ext_z;
        break;
    default:
        return;
        break;
    }

    check_ext_a:
    if(strcmp(extension, "a") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "aab") == 0){strcpy(result, "application/x-authorware-bin"); return;}
    if(strcmp(extension, "aam") == 0){strcpy(result, "application/x-authorware-map"); return;}
    if(strcmp(extension, "aas") == 0){strcpy(result, "application/x-authorware-seg"); return;}
    if(strcmp(extension, "abc") == 0){strcpy(result, "text/vndabc"); return;}
    if(strcmp(extension, "acgi") == 0){strcpy(result, "text/html"); return;}
    if(strcmp(extension, "afl") == 0){strcpy(result, "video/animaflex"); return;}
    if(strcmp(extension, "ai") == 0){strcpy(result, "application/postscript"); return;}
    if(strcmp(extension, "aif") == 0){strcpy(result, "audio/x-aiff"); return;}
    if(strcmp(extension, "aifc") == 0){strcpy(result, "audio/x-aiff"); return;}
    if(strcmp(extension, "aiff") == 0){strcpy(result, "audio/x-aiff"); return;}
    if(strcmp(extension, "aim") == 0){strcpy(result, "application/x-aim"); return;}
    if(strcmp(extension, "aip") == 0){strcpy(result, "text/x-audiosoft-intra"); return;}
    if(strcmp(extension, "ani") == 0){strcpy(result, "application/x-navi-animation"); return;}
    if(strcmp(extension, "aos") == 0){strcpy(result, "application/x-nokia-9000-communicator-add-on-software"); return;}
    if(strcmp(extension, "aps") == 0){strcpy(result, "application/mime"); return;}
    if(strcmp(extension, "arc") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "arj") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "art") == 0){strcpy(result, "image/x-jg"); return;}
    if(strcmp(extension, "asf") == 0){strcpy(result, "video/x-ms-asf"); return;}
    if(strcmp(extension, "asm") == 0){strcpy(result, "text/x-asm"); return;}
    if(strcmp(extension, "asp") == 0){strcpy(result, "text/asp"); return;}
    if(strcmp(extension, "asx") == 0){strcpy(result, "video/x-ms-asf-plugin"); return;}
    if(strcmp(extension, "au") == 0){strcpy(result, "audio/x-au"); return;}
    if(strcmp(extension, "avi") == 0){strcpy(result, "video/x-msvideo"); return;}
    if(strcmp(extension, "avs") == 0){strcpy(result, "video/avs-video"); return;}
    return;

    check_ext_b:
    if(strcmp(extension, "bcpio") == 0){strcpy(result, "application/x-bcpio"); return;}
    if(strcmp(extension, "bin") == 0){strcpy(result, "application/x-macbinary"); return;}
    if(strcmp(extension, "bm") == 0){strcpy(result, "image/bmp"); return;}
    if(strcmp(extension, "bmp") == 0){strcpy(result, "image/x-windows-bmp"); return;}
    if(strcmp(extension, "boo") == 0){strcpy(result, "application/book"); return;}
    if(strcmp(extension, "book") == 0){strcpy(result, "application/book"); return;}
    if(strcmp(extension, "boz") == 0){strcpy(result, "application/x-bzip2"); return;}
    if(strcmp(extension, "bsh") == 0){strcpy(result, "application/x-bsh"); return;}
    if(strcmp(extension, "bz") == 0){strcpy(result, "application/x-bzip"); return;}
    if(strcmp(extension, "bz2") == 0){strcpy(result, "application/x-bzip2"); return;}
    return;

    check_ext_c:
    if(strcmp(extension, "c") == 0){strcpy(result, "text/x-c"); return;}
    if(strcmp(extension, "c++") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "cat") == 0){strcpy(result, "application/vndms-pkiseccat"); return;}
    if(strcmp(extension, "cc") == 0){strcpy(result, "text/x-c"); return;}
    if(strcmp(extension, "ccad") == 0){strcpy(result, "application/clariscad"); return;}
    if(strcmp(extension, "cco") == 0){strcpy(result, "application/x-cocoa"); return;}
    if(strcmp(extension, "cdf") == 0){strcpy(result, "application/x-netcdf"); return;}
    if(strcmp(extension, "cer") == 0){strcpy(result, "application/x-x509-ca-cert"); return;}
    if(strcmp(extension, "cha") == 0){strcpy(result, "application/x-chat"); return;}
    if(strcmp(extension, "chat") == 0){strcpy(result, "application/x-chat"); return;}
    if(strcmp(extension, "class") == 0){strcpy(result, "application/x-java-class"); return;}
    if(strcmp(extension, "com") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "conf") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "cpio") == 0){strcpy(result, "application/x-cpio"); return;}
    if(strcmp(extension, "cpp") == 0){strcpy(result, "text/x-c"); return;}
    if(strcmp(extension, "cpt") == 0){strcpy(result, "application/x-cpt"); return;}
    if(strcmp(extension, "crl") == 0){strcpy(result, "application/pkix-crl"); return;}
    if(strcmp(extension, "crt") == 0){strcpy(result, "application/x-x509-user-cert"); return;}
    if(strcmp(extension, "csh") == 0){strcpy(result, "text/x-scriptcsh"); return;}
    if(strcmp(extension, "css") == 0){strcpy(result, "text/css"); return;}
    if(strcmp(extension, "cxx") == 0){strcpy(result, "text/plain"); return;}
    return;

    check_ext_d:
    if(strcmp(extension, "dcr") == 0){strcpy(result, "application/x-director"); return;}
    if(strcmp(extension, "deepv") == 0){strcpy(result, "application/x-deepv"); return;}
    if(strcmp(extension, "def") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "der") == 0){strcpy(result, "application/x-x509-ca-cert"); return;}
    if(strcmp(extension, "dif") == 0){strcpy(result, "video/x-dv"); return;}
    if(strcmp(extension, "dir") == 0){strcpy(result, "application/x-director"); return;}
    if(strcmp(extension, "dl") == 0){strcpy(result, "video/x-dl"); return;}
    if(strcmp(extension, "doc") == 0){strcpy(result, "application/msword"); return;}
    if(strcmp(extension, "dot") == 0){strcpy(result, "application/msword"); return;}
    if(strcmp(extension, "dp") == 0){strcpy(result, "application/commonground"); return;}
    if(strcmp(extension, "drw") == 0){strcpy(result, "application/drafting"); return;}
    if(strcmp(extension, "dump") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "dv") == 0){strcpy(result, "video/x-dv"); return;}
    if(strcmp(extension, "dvi") == 0){strcpy(result, "application/x-dvi"); return;}
    if(strcmp(extension, "dwf") == 0){strcpy(result, "model/vnddwf"); return;}
    if(strcmp(extension, "dwg") == 0){strcpy(result, "image/x-dwg"); return;}
    if(strcmp(extension, "dxf") == 0){strcpy(result, "image/x-dwg"); return;}
    if(strcmp(extension, "dxr") == 0){strcpy(result, "application/x-director"); return;}
    return;

    check_ext_e:
    if(strcmp(extension, "el") == 0){strcpy(result, "text/x-scriptelisp"); return;}
    if(strcmp(extension, "elc") == 0){strcpy(result, "application/x-elc"); return;}
    if(strcmp(extension, "env") == 0){strcpy(result, "application/x-envoy"); return;}
    if(strcmp(extension, "eps") == 0){strcpy(result, "application/postscript"); return;}
    if(strcmp(extension, "es") == 0){strcpy(result, "application/x-esrehber"); return;}
    if(strcmp(extension, "etx") == 0){strcpy(result, "text/x-setext"); return;}
    if(strcmp(extension, "evy") == 0){strcpy(result, "application/x-envoy"); return;}
    if(strcmp(extension, "exe") == 0){strcpy(result, "application/octet-stream"); return;}
    return;

    check_ext_f:
    if(strcmp(extension, "f") == 0){strcpy(result, "text/x-fortran"); return;}
    if(strcmp(extension, "f77") == 0){strcpy(result, "text/x-fortran"); return;}
    if(strcmp(extension, "f90") == 0){strcpy(result, "text/x-fortran"); return;}
    if(strcmp(extension, "fdf") == 0){strcpy(result, "application/vndfdf"); return;}
    if(strcmp(extension, "fif") == 0){strcpy(result, "image/fif"); return;}
    if(strcmp(extension, "fli") == 0){strcpy(result, "video/x-fli"); return;}
    if(strcmp(extension, "flo") == 0){strcpy(result, "image/florian"); return;}
    if(strcmp(extension, "flx") == 0){strcpy(result, "text/vndfmiflexstor"); return;}
    if(strcmp(extension, "fmf") == 0){strcpy(result, "video/x-atomic3d-feature"); return;}
    if(strcmp(extension, "for") == 0){strcpy(result, "text/x-fortran"); return;}
    if(strcmp(extension, "fpx") == 0){strcpy(result, "image/vndnet-fpx"); return;}
    if(strcmp(extension, "frl") == 0){strcpy(result, "application/freeloader"); return;}
    if(strcmp(extension, "funk") == 0){strcpy(result, "audio/make"); return;}
    return;

    check_ext_g:
    if(strcmp(extension, "g") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "g3") == 0){strcpy(result, "image/g3fax"); return;}
    if(strcmp(extension, "gif") == 0){strcpy(result, "image/gif"); return;}
    if(strcmp(extension, "gl") == 0){strcpy(result, "video/x-gl"); return;}
    if(strcmp(extension, "gsd") == 0){strcpy(result, "audio/x-gsm"); return;}
    if(strcmp(extension, "gsm") == 0){strcpy(result, "audio/x-gsm"); return;}
    if(strcmp(extension, "gsp") == 0){strcpy(result, "application/x-gsp"); return;}
    if(strcmp(extension, "gss") == 0){strcpy(result, "application/x-gss"); return;}
    if(strcmp(extension, "gtar") == 0){strcpy(result, "application/x-gtar"); return;}
    if(strcmp(extension, "gz") == 0){strcpy(result, "application/x-gzip"); return;}
    if(strcmp(extension, "gzip") == 0){strcpy(result, "multipart/x-gzip"); return;}
    return;

    check_ext_h:
    if(strcmp(extension, "h") == 0){strcpy(result, "text/x-h"); return;}
    if(strcmp(extension, "hdf") == 0){strcpy(result, "application/x-hdf"); return;}
    if(strcmp(extension, "help") == 0){strcpy(result, "application/x-helpfile"); return;}
    if(strcmp(extension, "hgl") == 0){strcpy(result, "application/vndhp-hpgl"); return;}
    if(strcmp(extension, "hh") == 0){strcpy(result, "text/x-h"); return;}
    if(strcmp(extension, "hlb") == 0){strcpy(result, "text/x-script"); return;}
    if(strcmp(extension, "hlp") == 0){strcpy(result, "application/x-winhelp"); return;}
    if(strcmp(extension, "hpg") == 0){strcpy(result, "application/vndhp-hpgl"); return;}
    if(strcmp(extension, "hpgl") == 0){strcpy(result, "application/vndhp-hpgl"); return;}
    if(strcmp(extension, "hqx") == 0){strcpy(result, "application/x-mac-binhex40"); return;}
    if(strcmp(extension, "hta") == 0){strcpy(result, "application/hta"); return;}
    if(strcmp(extension, "htc") == 0){strcpy(result, "text/x-component"); return;}
    if(strcmp(extension, "htm") == 0){strcpy(result, "text/html"); return;}
    if(strcmp(extension, "html") == 0){strcpy(result, "text/html"); return;}
    if(strcmp(extension, "htmls") == 0){strcpy(result, "text/html"); return;}
    if(strcmp(extension, "htt") == 0){strcpy(result, "text/webviewhtml"); return;}
    if(strcmp(extension, "htx") == 0){strcpy(result, "text/html"); return;}
    return;

    check_ext_i:
    if(strcmp(extension, "ice") == 0){strcpy(result, "x-conference/x-cooltalk"); return;}
    if(strcmp(extension, "ico") == 0){strcpy(result, "image/x-icon"); return;}
    if(strcmp(extension, "idc") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "ief") == 0){strcpy(result, "image/ief"); return;}
    if(strcmp(extension, "iefs") == 0){strcpy(result, "image/ief"); return;}
    if(strcmp(extension, "iges") == 0){strcpy(result, "model/iges"); return;}
    if(strcmp(extension, "igs") == 0){strcpy(result, "model/iges"); return;}
    if(strcmp(extension, "ima") == 0){strcpy(result, "application/x-ima"); return;}
    if(strcmp(extension, "imap") == 0){strcpy(result, "application/x-httpd-imap"); return;}
    if(strcmp(extension, "inf") == 0){strcpy(result, "application/inf"); return;}
    if(strcmp(extension, "ins") == 0){strcpy(result, "application/x-internett-signup"); return;}
    if(strcmp(extension, "ip") == 0){strcpy(result, "application/x-ip2"); return;}
    if(strcmp(extension, "isu") == 0){strcpy(result, "video/x-isvideo"); return;}
    if(strcmp(extension, "it") == 0){strcpy(result, "audio/it"); return;}
    if(strcmp(extension, "iv") == 0){strcpy(result, "application/x-inventor"); return;}
    if(strcmp(extension, "ivr") == 0){strcpy(result, "i-world/i-vrml"); return;}
    if(strcmp(extension, "ivy") == 0){strcpy(result, "application/x-livescreen"); return;}
    return;

    check_ext_j:
    if(strcmp(extension, "jam") == 0){strcpy(result, "audio/x-jam"); return;}
    if(strcmp(extension, "jav") == 0){strcpy(result, "text/x-java-source"); return;}
    if(strcmp(extension, "java") == 0){strcpy(result, "text/x-java-source"); return;}
    if(strcmp(extension, "jcm") == 0){strcpy(result, "application/x-java-commerce"); return;}
    if(strcmp(extension, "jfif") == 0){strcpy(result, "image/pjpeg"); return;}
    if(strcmp(extension, "jfif-tbnl") == 0){strcpy(result, "image/jpeg"); return;}
    if(strcmp(extension, "jpe") == 0){strcpy(result, "image/pjpeg"); return;}
    if(strcmp(extension, "jpeg") == 0){strcpy(result, "image/pjpeg"); return;}
    if(strcmp(extension, "jpg") == 0){strcpy(result, "image/pjpeg"); return;}
    if(strcmp(extension, "jps") == 0){strcpy(result, "image/x-jps"); return;}
    if(strcmp(extension, "js") == 0){strcpy(result, "application/x-javascript"); return;}
    if(strcmp(extension, "jut") == 0){strcpy(result, "image/jutvision"); return;}
    return;

    check_ext_k:
    if(strcmp(extension, "kar") == 0){strcpy(result, "music/x-karaoke"); return;}
    if(strcmp(extension, "ksh") == 0){strcpy(result, "text/x-scriptksh"); return;}
    return;

    check_ext_l:
    if(strcmp(extension, "la") == 0){strcpy(result, "audio/x-nspaudio"); return;}
    if(strcmp(extension, "lam") == 0){strcpy(result, "audio/x-liveaudio"); return;}
    if(strcmp(extension, "latex") == 0){strcpy(result, "application/x-latex"); return;}
    if(strcmp(extension, "lha") == 0){strcpy(result, "application/x-lha"); return;}
    if(strcmp(extension, "lhx") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "list") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "lma") == 0){strcpy(result, "audio/x-nspaudio"); return;}
    if(strcmp(extension, "log") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "lsp") == 0){strcpy(result, "text/x-scriptlisp"); return;}
    if(strcmp(extension, "lst") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "lsx") == 0){strcpy(result, "text/x-la-asf"); return;}
    if(strcmp(extension, "ltx") == 0){strcpy(result, "application/x-latex"); return;}
    if(strcmp(extension, "lzh") == 0){strcpy(result, "application/x-lzh"); return;}
    if(strcmp(extension, "lzx") == 0){strcpy(result, "application/x-lzx"); return;}
    return;

    check_ext_m:
    if(strcmp(extension, "m") == 0){strcpy(result, "text/x-m"); return;}
    if(strcmp(extension, "m1v") == 0){strcpy(result, "video/mpeg"); return;}
    if(strcmp(extension, "m2a") == 0){strcpy(result, "audio/mpeg"); return;}
    if(strcmp(extension, "m2v") == 0){strcpy(result, "video/mpeg"); return;}
    if(strcmp(extension, "m3u") == 0){strcpy(result, "audio/x-mpequrl"); return;}
    if(strcmp(extension, "man") == 0){strcpy(result, "application/x-troff-man"); return;}
    if(strcmp(extension, "map") == 0){strcpy(result, "application/x-navimap"); return;}
    if(strcmp(extension, "mar") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "mbd") == 0){strcpy(result, "application/mbedlet"); return;}
    if(strcmp(extension, "mc$") == 0){strcpy(result, "application/x-magic-cap-package-10"); return;}
    if(strcmp(extension, "mcd") == 0){strcpy(result, "application/x-mathcad"); return;}
    if(strcmp(extension, "mcf") == 0){strcpy(result, "text/mcf"); return;}
    if(strcmp(extension, "mcp") == 0){strcpy(result, "application/netmc"); return;}
    if(strcmp(extension, "me") == 0){strcpy(result, "application/x-troff-me"); return;}
    if(strcmp(extension, "mht") == 0){strcpy(result, "message/rfc822"); return;}
    if(strcmp(extension, "mhtml") == 0){strcpy(result, "message/rfc822"); return;}
    if(strcmp(extension, "mid") == 0){strcpy(result, "x-music/x-midi"); return;}
    if(strcmp(extension, "midi") == 0){strcpy(result, "x-music/x-midi"); return;}
    if(strcmp(extension, "mif") == 0){strcpy(result, "application/x-mif"); return;}
    if(strcmp(extension, "mime") == 0){strcpy(result, "www/mime"); return;}
    if(strcmp(extension, "mjf") == 0){strcpy(result, "audio/x-vndaudioexplosionmjuicemediafile"); return;}
    if(strcmp(extension, "mjpg") == 0){strcpy(result, "video/x-motion-jpeg"); return;}
    if(strcmp(extension, "mm") == 0){strcpy(result, "application/x-meme"); return;}
    if(strcmp(extension, "mme") == 0){strcpy(result, "application/base64"); return;}
    if(strcmp(extension, "mod") == 0){strcpy(result, "audio/x-mod"); return;}
    if(strcmp(extension, "moov") == 0){strcpy(result, "video/quicktime"); return;}
    if(strcmp(extension, "mov") == 0){strcpy(result, "video/quicktime"); return;}
    if(strcmp(extension, "movie") == 0){strcpy(result, "video/x-sgi-movie"); return;}
    if(strcmp(extension, "mp2") == 0){strcpy(result, "video/x-mpeq2a"); return;}
    if(strcmp(extension, "mp3") == 0){strcpy(result, "video/x-mpeg"); return;}
    if(strcmp(extension, "mpa") == 0){strcpy(result, "video/mpeg"); return;}
    if(strcmp(extension, "mpc") == 0){strcpy(result, "application/x-project"); return;}
    if(strcmp(extension, "mpe") == 0){strcpy(result, "video/mpeg"); return;}
    if(strcmp(extension, "mpeg") == 0){strcpy(result, "video/mpeg"); return;}
    if(strcmp(extension, "mpg") == 0){strcpy(result, "video/mpeg"); return;}
    if(strcmp(extension, "mpga") == 0){strcpy(result, "audio/mpeg"); return;}
    if(strcmp(extension, "mpp") == 0){strcpy(result, "application/vndms-project"); return;}
    if(strcmp(extension, "mpt") == 0){strcpy(result, "application/x-project"); return;}
    if(strcmp(extension, "mpv") == 0){strcpy(result, "application/x-project"); return;}
    if(strcmp(extension, "mpx") == 0){strcpy(result, "application/x-project"); return;}
    if(strcmp(extension, "mrc") == 0){strcpy(result, "application/marc"); return;}
    if(strcmp(extension, "ms") == 0){strcpy(result, "application/x-troff-ms"); return;}
    if(strcmp(extension, "mv") == 0){strcpy(result, "video/x-sgi-movie"); return;}
    if(strcmp(extension, "my") == 0){strcpy(result, "audio/make"); return;}
    if(strcmp(extension, "mzz") == 0){strcpy(result, "application/x-vndaudioexplosionmzz"); return;}
    return;

    check_ext_n:
    if(strcmp(extension, "nap") == 0){strcpy(result, "image/naplps"); return;}
    if(strcmp(extension, "naplps") == 0){strcpy(result, "image/naplps"); return;}
    if(strcmp(extension, "nc") == 0){strcpy(result, "application/x-netcdf"); return;}
    if(strcmp(extension, "ncm") == 0){strcpy(result, "application/vndnokiaconfiguration-message"); return;}
    if(strcmp(extension, "nif") == 0){strcpy(result, "image/x-niff"); return;}
    if(strcmp(extension, "niff") == 0){strcpy(result, "image/x-niff"); return;}
    if(strcmp(extension, "nix") == 0){strcpy(result, "application/x-mix-transfer"); return;}
    if(strcmp(extension, "nsc") == 0){strcpy(result, "application/x-conference"); return;}
    if(strcmp(extension, "nvd") == 0){strcpy(result, "application/x-navidoc"); return;}
    return;

    check_ext_o:
    if(strcmp(extension, "o") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "oda") == 0){strcpy(result, "application/oda"); return;}
    if(strcmp(extension, "omc") == 0){strcpy(result, "application/x-omc"); return;}
    if(strcmp(extension, "omcd") == 0){strcpy(result, "application/x-omcdatamaker"); return;}
    if(strcmp(extension, "omcr") == 0){strcpy(result, "application/x-omcregerator"); return;}
    return;

    check_ext_p:
    if(strcmp(extension, "p") == 0){strcpy(result, "text/x-pascal"); return;}
    if(strcmp(extension, "p10") == 0){strcpy(result, "application/x-pkcs10"); return;}
    if(strcmp(extension, "p12") == 0){strcpy(result, "application/x-pkcs12"); return;}
    if(strcmp(extension, "p7a") == 0){strcpy(result, "application/x-pkcs7-signature"); return;}
    if(strcmp(extension, "p7c") == 0){strcpy(result, "application/x-pkcs7-mime"); return;}
    if(strcmp(extension, "p7m") == 0){strcpy(result, "application/x-pkcs7-mime"); return;}
    if(strcmp(extension, "p7r") == 0){strcpy(result, "application/x-pkcs7-certreqresp"); return;}
    if(strcmp(extension, "p7s") == 0){strcpy(result, "application/pkcs7-signature"); return;}
    if(strcmp(extension, "part") == 0){strcpy(result, "application/pro_eng"); return;}
    if(strcmp(extension, "pas") == 0){strcpy(result, "text/pascal"); return;}
    if(strcmp(extension, "pbm") == 0){strcpy(result, "image/x-portable-bitmap"); return;}
    if(strcmp(extension, "pcl") == 0){strcpy(result, "application/x-pcl"); return;}
    if(strcmp(extension, "pct") == 0){strcpy(result, "image/x-pict"); return;}
    if(strcmp(extension, "pcx") == 0){strcpy(result, "image/x-pcx"); return;}
    if(strcmp(extension, "pdb") == 0){strcpy(result, "chemical/x-pdb"); return;}
    if(strcmp(extension, "pdf") == 0){strcpy(result, "application/pdf"); return;}
    if(strcmp(extension, "pfunk") == 0){strcpy(result, "audio/makemyfunk"); return;}
    if(strcmp(extension, "pgm") == 0){strcpy(result, "image/x-portable-greymap"); return;}
    if(strcmp(extension, "pic") == 0){strcpy(result, "image/pict"); return;}
    if(strcmp(extension, "pict") == 0){strcpy(result, "image/pict"); return;}
    if(strcmp(extension, "pkg") == 0){strcpy(result, "application/x-newton-compatible-pkg"); return;}
    if(strcmp(extension, "pko") == 0){strcpy(result, "application/vndms-pkipko"); return;}
    if(strcmp(extension, "pl") == 0){strcpy(result, "text/x-scriptperl"); return;}
    if(strcmp(extension, "plx") == 0){strcpy(result, "application/x-pixclscript"); return;}
    if(strcmp(extension, "pm") == 0){strcpy(result, "text/x-scriptperl-module"); return;}
    if(strcmp(extension, "pm4") == 0){strcpy(result, "application/x-pagemaker"); return;}
    if(strcmp(extension, "pm5") == 0){strcpy(result, "application/x-pagemaker"); return;}
    if(strcmp(extension, "png") == 0){strcpy(result, "image/png"); return;}
    if(strcmp(extension, "pnm") == 0){strcpy(result, "image/x-portable-anymap"); return;}
    if(strcmp(extension, "pot") == 0){strcpy(result, "application/vndms-powerpoint"); return;}
    if(strcmp(extension, "pov") == 0){strcpy(result, "model/x-pov"); return;}
    if(strcmp(extension, "ppa") == 0){strcpy(result, "application/vndms-powerpoint"); return;}
    if(strcmp(extension, "ppm") == 0){strcpy(result, "image/x-portable-pixmap"); return;}
    if(strcmp(extension, "pps") == 0){strcpy(result, "application/vndms-powerpoint"); return;}
    if(strcmp(extension, "ppt") == 0){strcpy(result, "application/x-mspowerpoint"); return;}
    if(strcmp(extension, "ppz") == 0){strcpy(result, "application/mspowerpoint"); return;}
    if(strcmp(extension, "pre") == 0){strcpy(result, "application/x-freelance"); return;}
    if(strcmp(extension, "prt") == 0){strcpy(result, "application/pro_eng"); return;}
    if(strcmp(extension, "ps") == 0){strcpy(result, "application/postscript"); return;}
    if(strcmp(extension, "psd") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "pvu") == 0){strcpy(result, "paleovu/x-pv"); return;}
    if(strcmp(extension, "pwz") == 0){strcpy(result, "application/vndms-powerpoint"); return;}
    if(strcmp(extension, "py") == 0){strcpy(result, "text/x-scriptphyton"); return;}
    if(strcmp(extension, "pyc") == 0){strcpy(result, "applicaiton/x-bytecodepython"); return;}
    return;

    check_ext_q:
    if(strcmp(extension, "qcp") == 0){strcpy(result, "audio/vndqcelp"); return;}
    if(strcmp(extension, "qd3") == 0){strcpy(result, "x-world/x-3dmf"); return;}
    if(strcmp(extension, "qd3d") == 0){strcpy(result, "x-world/x-3dmf"); return;}
    if(strcmp(extension, "qif") == 0){strcpy(result, "image/x-quicktime"); return;}
    if(strcmp(extension, "qt") == 0){strcpy(result, "video/quicktime"); return;}
    if(strcmp(extension, "qtc") == 0){strcpy(result, "video/x-qtc"); return;}
    if(strcmp(extension, "qti") == 0){strcpy(result, "image/x-quicktime"); return;}
    if(strcmp(extension, "qtif") == 0){strcpy(result, "image/x-quicktime"); return;}
    return;

    check_ext_r:
    if(strcmp(extension, "ra") == 0){strcpy(result, "audio/x-realaudio"); return;}
    if(strcmp(extension, "ram") == 0){strcpy(result, "audio/x-pn-realaudio"); return;}
    if(strcmp(extension, "ras") == 0){strcpy(result, "image/x-cmu-raster"); return;}
    if(strcmp(extension, "rast") == 0){strcpy(result, "image/cmu-raster"); return;}
    if(strcmp(extension, "rexx") == 0){strcpy(result, "text/x-scriptrexx"); return;}
    if(strcmp(extension, "rf") == 0){strcpy(result, "image/vndrn-realflash"); return;}
    if(strcmp(extension, "rgb") == 0){strcpy(result, "image/x-rgb"); return;}
    if(strcmp(extension, "rm") == 0){strcpy(result, "audio/x-pn-realaudio"); return;}
    if(strcmp(extension, "rmi") == 0){strcpy(result, "audio/mid"); return;}
    if(strcmp(extension, "rmm") == 0){strcpy(result, "audio/x-pn-realaudio"); return;}
    if(strcmp(extension, "rmp") == 0){strcpy(result, "audio/x-pn-realaudio-plugin"); return;}
    if(strcmp(extension, "rng") == 0){strcpy(result, "application/vndnokiaringing-tone"); return;}
    if(strcmp(extension, "rnx") == 0){strcpy(result, "application/vndrn-realplayer"); return;}
    if(strcmp(extension, "roff") == 0){strcpy(result, "application/x-troff"); return;}
    if(strcmp(extension, "rp") == 0){strcpy(result, "image/vndrn-realpix"); return;}
    if(strcmp(extension, "rpm") == 0){strcpy(result, "audio/x-pn-realaudio-plugin"); return;}
    if(strcmp(extension, "rt") == 0){strcpy(result, "text/vndrn-realtext"); return;}
    if(strcmp(extension, "rtf") == 0){strcpy(result, "text/richtext"); return;}
    if(strcmp(extension, "rtx") == 0){strcpy(result, "text/richtext"); return;}
    if(strcmp(extension, "rv") == 0){strcpy(result, "video/vndrn-realvideo"); return;}
    return;

    check_ext_s:
    if(strcmp(extension, "s") == 0){strcpy(result, "text/x-asm"); return;}
    if(strcmp(extension, "s3m") == 0){strcpy(result, "audio/s3m"); return;}
    if(strcmp(extension, "saveme") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "sbk") == 0){strcpy(result, "application/x-tbook"); return;}
    if(strcmp(extension, "scm") == 0){strcpy(result, "video/x-scm"); return;}
    if(strcmp(extension, "sdml") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "sdp") == 0){strcpy(result, "application/x-sdp"); return;}
    if(strcmp(extension, "sdr") == 0){strcpy(result, "application/sounder"); return;}
    if(strcmp(extension, "sea") == 0){strcpy(result, "application/x-sea"); return;}
    if(strcmp(extension, "set") == 0){strcpy(result, "application/set"); return;}
    if(strcmp(extension, "sgm") == 0){strcpy(result, "text/x-sgml"); return;}
    if(strcmp(extension, "sgml") == 0){strcpy(result, "text/x-sgml"); return;}
    if(strcmp(extension, "sh") == 0){strcpy(result, "text/x-scriptsh"); return;}
    if(strcmp(extension, "shar") == 0){strcpy(result, "application/x-shar"); return;}
    if(strcmp(extension, "shtml") == 0){strcpy(result, "text/x-server-parsed-html"); return;}
    if(strcmp(extension, "sid") == 0){strcpy(result, "audio/x-psid"); return;}
    if(strcmp(extension, "sit") == 0){strcpy(result, "application/x-stuffit"); return;}
    if(strcmp(extension, "skd") == 0){strcpy(result, "application/x-koan"); return;}
    if(strcmp(extension, "skm") == 0){strcpy(result, "application/x-koan"); return;}
    if(strcmp(extension, "skp") == 0){strcpy(result, "application/x-koan"); return;}
    if(strcmp(extension, "skt") == 0){strcpy(result, "application/x-koan"); return;}
    if(strcmp(extension, "sl") == 0){strcpy(result, "application/x-seelogo"); return;}
    if(strcmp(extension, "smi") == 0){strcpy(result, "application/smil"); return;}
    if(strcmp(extension, "smil") == 0){strcpy(result, "application/smil"); return;}
    if(strcmp(extension, "snd") == 0){strcpy(result, "audio/x-adpcm"); return;}
    if(strcmp(extension, "sol") == 0){strcpy(result, "application/solids"); return;}
    if(strcmp(extension, "spc") == 0){strcpy(result, "text/x-speech"); return;}
    if(strcmp(extension, "spl") == 0){strcpy(result, "application/futuresplash"); return;}
    if(strcmp(extension, "spr") == 0){strcpy(result, "application/x-sprite"); return;}
    if(strcmp(extension, "sprite") == 0){strcpy(result, "application/x-sprite"); return;}
    if(strcmp(extension, "src") == 0){strcpy(result, "application/x-wais-source"); return;}
    if(strcmp(extension, "ssi") == 0){strcpy(result, "text/x-server-parsed-html"); return;}
    if(strcmp(extension, "ssm") == 0){strcpy(result, "application/streamingmedia"); return;}
    if(strcmp(extension, "sst") == 0){strcpy(result, "application/vndms-pkicertstore"); return;}
    if(strcmp(extension, "step") == 0){strcpy(result, "application/step"); return;}
    if(strcmp(extension, "stl") == 0){strcpy(result, "application/x-navistyle"); return;}
    if(strcmp(extension, "stp") == 0){strcpy(result, "application/step"); return;}
    if(strcmp(extension, "sv4cpio") == 0){strcpy(result, "application/x-sv4cpio"); return;}
    if(strcmp(extension, "sv4crc") == 0){strcpy(result, "application/x-sv4crc"); return;}
    if(strcmp(extension, "svf") == 0){strcpy(result, "image/x-dwg"); return;}
    if(strcmp(extension, "svr") == 0){strcpy(result, "x-world/x-svr"); return;}
    if(strcmp(extension, "swf") == 0){strcpy(result, "application/x-shockwave-flash"); return;}
    return;

    check_ext_t:
    if(strcmp(extension, "t") == 0){strcpy(result, "application/x-troff"); return;}
    if(strcmp(extension, "talk") == 0){strcpy(result, "text/x-speech"); return;}
    if(strcmp(extension, "tar") == 0){strcpy(result, "application/x-tar"); return;}
    if(strcmp(extension, "tbk") == 0){strcpy(result, "application/x-tbook"); return;}
    if(strcmp(extension, "tcl") == 0){strcpy(result, "text/x-scripttcl"); return;}
    if(strcmp(extension, "tcsh") == 0){strcpy(result, "text/x-scripttcsh"); return;}
    if(strcmp(extension, "tex") == 0){strcpy(result, "application/x-tex"); return;}
    if(strcmp(extension, "texi") == 0){strcpy(result, "application/x-texinfo"); return;}
    if(strcmp(extension, "texinfo") == 0){strcpy(result, "application/x-texinfo"); return;}
    if(strcmp(extension, "text") == 0){strcpy(result, "text/plain"); return;}
    if(strcmp(extension, "tgz") == 0){strcpy(result, "application/x-compressed"); return;}
    if(strcmp(extension, "tif") == 0){strcpy(result, "image/x-tiff"); return;}
    if(strcmp(extension, "tiff") == 0){strcpy(result, "image/x-tiff"); return;}
    if(strcmp(extension, "tr") == 0){strcpy(result, "application/x-troff"); return;}
    if(strcmp(extension, "tsi") == 0){strcpy(result, "audio/tsp-audio"); return;}
    if(strcmp(extension, "tsp") == 0){strcpy(result, "audio/tsplayer"); return;}
    if(strcmp(extension, "tsv") == 0){strcpy(result, "text/tab-separated-values"); return;}
    if(strcmp(extension, "turbot") == 0){strcpy(result, "image/florian"); return;}
    if(strcmp(extension, "txt") == 0){strcpy(result, "text/plain"); return;}
    return;

    check_ext_u:
    if(strcmp(extension, "uil") == 0){strcpy(result, "text/x-uil"); return;}
    if(strcmp(extension, "uni") == 0){strcpy(result, "text/uri-list"); return;}
    if(strcmp(extension, "unis") == 0){strcpy(result, "text/uri-list"); return;}
    if(strcmp(extension, "unv") == 0){strcpy(result, "application/i-deas"); return;}
    if(strcmp(extension, "uri") == 0){strcpy(result, "text/uri-list"); return;}
    if(strcmp(extension, "uris") == 0){strcpy(result, "text/uri-list"); return;}
    if(strcmp(extension, "ustar") == 0){strcpy(result, "multipart/x-ustar"); return;}
    if(strcmp(extension, "uu") == 0){strcpy(result, "text/x-uuencode"); return;}
    if(strcmp(extension, "uue") == 0){strcpy(result, "text/x-uuencode"); return;}
    return;

    check_ext_v:
    if(strcmp(extension, "vcd") == 0){strcpy(result, "application/x-cdlink"); return;}
    if(strcmp(extension, "vcs") == 0){strcpy(result, "text/x-vcalendar"); return;}
    if(strcmp(extension, "vda") == 0){strcpy(result, "application/vda"); return;}
    if(strcmp(extension, "vdo") == 0){strcpy(result, "video/vdo"); return;}
    if(strcmp(extension, "vew") == 0){strcpy(result, "application/groupwise"); return;}
    if(strcmp(extension, "viv") == 0){strcpy(result, "video/vndvivo"); return;}
    if(strcmp(extension, "vivo") == 0){strcpy(result, "video/vndvivo"); return;}
    if(strcmp(extension, "vmd") == 0){strcpy(result, "application/vocaltec-media-desc"); return;}
    if(strcmp(extension, "vmf") == 0){strcpy(result, "application/vocaltec-media-file"); return;}
    if(strcmp(extension, "voc") == 0){strcpy(result, "audio/x-voc"); return;}
    if(strcmp(extension, "vos") == 0){strcpy(result, "video/vosaic"); return;}
    if(strcmp(extension, "vox") == 0){strcpy(result, "audio/voxware"); return;}
    if(strcmp(extension, "vqe") == 0){strcpy(result, "audio/x-twinvq-plugin"); return;}
    if(strcmp(extension, "vqf") == 0){strcpy(result, "audio/x-twinvq"); return;}
    if(strcmp(extension, "vql") == 0){strcpy(result, "audio/x-twinvq-plugin"); return;}
    if(strcmp(extension, "vrml") == 0){strcpy(result, "x-world/x-vrml"); return;}
    if(strcmp(extension, "vrt") == 0){strcpy(result, "x-world/x-vrt"); return;}
    if(strcmp(extension, "vsd") == 0){strcpy(result, "application/x-visio"); return;}
    if(strcmp(extension, "vst") == 0){strcpy(result, "application/x-visio"); return;}
    if(strcmp(extension, "vsw") == 0){strcpy(result, "application/x-visio"); return;}
    return;

    check_ext_w:
    if(strcmp(extension, "w60") == 0){strcpy(result, "application/wordperfect60"); return;}
    if(strcmp(extension, "w61") == 0){strcpy(result, "application/wordperfect61"); return;}
    if(strcmp(extension, "w6w") == 0){strcpy(result, "application/msword"); return;}
    if(strcmp(extension, "wav") == 0){strcpy(result, "audio/x-wav"); return;}
    if(strcmp(extension, "wb1") == 0){strcpy(result, "application/x-qpro"); return;}
    if(strcmp(extension, "wbmp") == 0){strcpy(result, "image/vndwapwbmp"); return;}
    if(strcmp(extension, "web") == 0){strcpy(result, "application/vndxara"); return;}
    if(strcmp(extension, "wiz") == 0){strcpy(result, "application/msword"); return;}
    if(strcmp(extension, "wk1") == 0){strcpy(result, "application/x-123"); return;}
    if(strcmp(extension, "wmf") == 0){strcpy(result, "windows/metafile"); return;}
    if(strcmp(extension, "wml") == 0){strcpy(result, "text/vndwapwml"); return;}
    if(strcmp(extension, "wmlc") == 0){strcpy(result, "application/vndwapwmlc"); return;}
    if(strcmp(extension, "wmls") == 0){strcpy(result, "text/vndwapwmlscript"); return;}
    if(strcmp(extension, "wmlsc") == 0){strcpy(result, "application/vndwapwmlscriptc"); return;}
    if(strcmp(extension, "word") == 0){strcpy(result, "application/msword"); return;}
    if(strcmp(extension, "wp") == 0){strcpy(result, "application/wordperfect"); return;}
    if(strcmp(extension, "wp5") == 0){strcpy(result, "application/wordperfect60"); return;}
    if(strcmp(extension, "wp6") == 0){strcpy(result, "application/wordperfect"); return;}
    if(strcmp(extension, "wpd") == 0){strcpy(result, "application/x-wpwin"); return;}
    if(strcmp(extension, "wq1") == 0){strcpy(result, "application/x-lotus"); return;}
    if(strcmp(extension, "wri") == 0){strcpy(result, "application/x-wri"); return;}
    if(strcmp(extension, "wrl") == 0){strcpy(result, "x-world/x-vrml"); return;}
    if(strcmp(extension, "wrz") == 0){strcpy(result, "x-world/x-vrml"); return;}
    if(strcmp(extension, "wsc") == 0){strcpy(result, "text/scriplet"); return;}
    if(strcmp(extension, "wsrc") == 0){strcpy(result, "application/x-wais-source"); return;}
    if(strcmp(extension, "wtk") == 0){strcpy(result, "application/x-wintalk"); return;}
    return;

    check_ext_x:
    if(strcmp(extension, "xbm") == 0){strcpy(result, "image/xbm"); return;}
    if(strcmp(extension, "xdr") == 0){strcpy(result, "video/x-amt-demorun"); return;}
    if(strcmp(extension, "xgz") == 0){strcpy(result, "xgl/drawing"); return;}
    if(strcmp(extension, "xif") == 0){strcpy(result, "image/vndxiff"); return;}
    if(strcmp(extension, "xl") == 0){strcpy(result, "application/excel"); return;}
    if(strcmp(extension, "xla") == 0){strcpy(result, "application/x-msexcel"); return;}
    if(strcmp(extension, "xlb") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xlc") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xld") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xlk") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xll") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xlm") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xls") == 0){strcpy(result, "application/x-msexcel"); return;}
    if(strcmp(extension, "xlt") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xlv") == 0){strcpy(result, "application/x-excel"); return;}
    if(strcmp(extension, "xlw") == 0){strcpy(result, "application/x-msexcel"); return;}
    if(strcmp(extension, "xm") == 0){strcpy(result, "audio/xm"); return;}
    if(strcmp(extension, "xml") == 0){strcpy(result, "text/xml"); return;}
    if(strcmp(extension, "xmz") == 0){strcpy(result, "xgl/movie"); return;}
    if(strcmp(extension, "xpix") == 0){strcpy(result, "application/x-vndls-xpix"); return;}
    if(strcmp(extension, "xpm") == 0){strcpy(result, "image/xpm"); return;}
    if(strcmp(extension, "x-png") == 0){strcpy(result, "image/png"); return;}
    if(strcmp(extension, "xsr") == 0){strcpy(result, "video/x-amt-showrun"); return;}
    if(strcmp(extension, "xwd") == 0){strcpy(result, "image/x-xwindowdump"); return;}
    if(strcmp(extension, "xyz") == 0){strcpy(result, "chemical/x-pdb"); return;}
    return;

    check_ext_z:
    if(strcmp(extension, "z") == 0){strcpy(result, "application/x-compressed"); return;}
    if(strcmp(extension, "zip") == 0){strcpy(result, "multipart/x-zip"); return;}
    if(strcmp(extension, "zoo") == 0){strcpy(result, "application/octet-stream"); return;}
    if(strcmp(extension, "zsh") == 0){strcpy(result, "text/x-scriptzsh"); return;}
    return;

}
